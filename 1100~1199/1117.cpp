#include <stdio.h>
#define M 1000000009
long long t[1<<21][5];
void init(int n,int s,int e){
    if(s==e){
        scanf("%lld",t[n]);
        return;
    }
    int l=n*2,r=l+1,m=(s+e)/2;
    init(l,s,m);
    init(r,m+1,e);
    t[n][0]=(t[l][0]+t[r][0])%M;
    t[n][1]=1;
}
void lazy(int n,int s,int e,int q,long long v){
    if(q<2){
        t[n][0]=t[n][0]*v%M,t[n][1]=t[n][1]*v%M,t[n][2]=t[n][2]*v%M;
        t[n][3]=t[n][4]=1;
    }
    else{
        t[n][0]=(t[n][0]+v*(e-s+1))%M,t[n][2]=(t[n][2]+v)%M;
        t[n][4]=1;
    }
}
void update(int n,int s,int e,int si,int ei,int q,long long v){
    if(ei<s||e<si)return;
    int l=n*2,r=l+1,m=(s+e)/2;
    if(t[n][3])lazy(l,s,m,1,t[n][1]),lazy(r,m+1,e,1,t[n][1]);
    if(t[n][4])lazy(l,s,m,2,t[n][2]),lazy(r,m+1,e,2,t[n][2]);
    t[n][1]=1,t[n][2]=t[n][3]=t[n][4]=0;
    if(si<=s&&e<=ei){
        lazy(n,s,e,q,v);
        return;
    }
    update(l,s,m,si,ei,q,v);
    update(r,m+1,e,si,ei,q,v);
    t[n][0]=(t[l][0]+t[r][0])%M;
}
int query(int n,int s,int e,int si,int ei){
    if(ei<s||e<si)return 0;
    if(si<=s&&e<=ei)return t[n][0];
    int l=n*2,r=l+1,m=(s+e)/2;
    if(t[n][3])lazy(l,s,m,1,t[n][1]),lazy(r,m+1,e,1,t[n][1]);
    if(t[n][4])lazy(l,s,m,2,t[n][2]),lazy(r,m+1,e,2,t[n][2]);
    t[n][1]=1,t[n][2]=t[n][3]=t[n][4]=0;
    return (query(l,s,m,si,ei)+query(r,m+1,e,si,ei))%M;
}
void fin(int n,int s,int e){
    if(s==e){
        printf("%d ",t[n][0]);
        return;
    }
    int l=n*2,r=l+1,m=(s+e)/2;
    if(t[n][3])lazy(l,s,m,1,t[n][1]),lazy(r,m+1,e,1,t[n][1]);
    if(t[n][4])lazy(l,s,m,2,t[n][2]),lazy(r,m+1,e,2,t[n][2]);
    t[n][1]=1,t[n][2]=t[n][3]=t[n][4]=0;
    fin(l,s,m);
    fin(r,m+1,e);
}
int main(){
    int n,q,p,l,r,c;
    scanf("%d%d",&n,&q);
    init(1,1,n);
    for(;q--;){
        scanf("%d%d%d",&p,&l,&r);
        if(p<3){
            scanf("%d",&c);
            update(1,1,n,l,r,p,c);
        }
        else printf("%d\n",query(1,1,n,l,r));
    }
    fin(1,1,n);
    return 0;
}
