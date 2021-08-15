#include <stdio.h>
#include <set>
using namespace std;
#define M 1000000007
struct data{
    int i,x,y;
    bool operator<(const data&r)const{
        return i<r.i;
    }
};
set<data> S;
int x[500010],y[500010],n;
int t[1<<21][2];
void update(int n,int s,int e,int k){
    if(s==e){
        t[n][0]=x[s];
        t[n][1]=y[s];
        return;
    }
    int l=n*2,r=l+1,m=(s+e)/2;
    if(k>m)update(r,m+1,e,k);
    else update(l,s,m,k);
    t[n][0]=(long long)t[l][0]*t[r][0]%M;
    t[n][1]=max(t[l][1],t[r][1]);
}
int mul(int n,int s,int e,int si,int ei){
    if(ei<s||e<si)return 1;
    if(si<=s&&e<=ei)return t[n][0];
    int l=n*2,r=l+1,m=(s+e)/2;
    return (long long)mul(l,s,m,si,ei)*mul(r,m+1,e,si,ei)%M;
}
int query(int n,int s,int e,int si,int ei){
    if(ei<s||e<si)return 0;
    if(si<=s&&e<=ei)return t[n][1];
    int l=n*2,r=l+1,m=(s+e)/2;
    return max(query(l,s,m,si,ei),query(r,m+1,e,si,ei));
}
int sol(){
    int p;
    long long m=1,t,ans=0;
    set<data>::iterator it=S.end();
    if(it==S.begin())return query(1,1,n,1,n);
    for(--it;it!=S.begin();--it){
        m*=it->x;
        if(m>=1e9)break;
    }
    if(it==S.begin()){
        m*=it->x;
        if(m<1e9){
            for(p=m=1;it!=S.end();++it){
                ans=max(ans,m*query(1,1,n,p,(it->i)-1));
                p=it->i;
                m*=it->x;
            }
            return max(ans,m*query(1,1,n,p,n))%M;
        }
    }
    p=it->i;
    t=mul(1,1,n,1,p);
    for(++it,m=1;it!=S.end();++it){
        ans=max(ans,m*query(1,1,n,p,(it->i)-1));
        p=it->i;
        m*=it->x;
    }
    return max(ans,m*query(1,1,n,p,n))%M*t%M;
}
int main(){
    int i,m,t,p,v;
    data tmp;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",x+i);
    for(i=1;i<=n;++i)scanf("%d",y+i);
    for(i=1;i<=n;++i){
        if(x[i]>1)S.insert(tmp={i,x[i],y[i]});
        update(1,1,n,i);
    }
    printf("%d\n",sol());
    scanf("%d",&m);
    for(;m--;){
        scanf("%d%d%d",&t,&p,&v);
        ++p;
        if(x[p]>1)S.erase(S.find(tmp={p,x[p],y[p]}));
        if(t<2)x[p]=v,update(1,1,n,p);
        else y[p]=v,update(1,1,n,p);
        if(x[p]>1)S.insert(tmp={p,x[p],y[p]});
        printf("%d\n",sol());
    }
    return 0;
}
