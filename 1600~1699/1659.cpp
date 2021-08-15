#include <stdio.h>
int a[100010],t[18][1<<19],st[100010][18];
void init(int k,int n,int s,int e){
    if(s==e){
        t[k][n]=s;
        return;
    }
    int l=n*2,r=l+1,m=(s+e)/2;
    init(k,l,s,m);
    init(k,r,m+1,e);
    if(st[t[k][l]][k]>st[t[k][r]][k])t[k][n]=t[k][l];
    else t[k][n]=t[k][r];
}
int query(int k,int n,int s,int e,int si,int ei){
    if(ei<s||e<si)return 0;
    if(si<=s&&e<=ei)return t[k][n];
    int l=n*2,r=l+1,m=(s+e)/2;
    int i=query(k,l,s,m,si,ei),j=query(k,r,m+1,e,si,ei);
    return st[i][k]>st[j][k]?i:j;
}
long long D[100010],ans;
int main(){
    int i,j,k,n,q,x,y;
    scanf("%d%d",&n,&q);
    for(i=1;i<n;++i)scanf("%d",a+i),st[i][0]=a[i];
    a[n]=st[n][0]=n;
    init(0,1,1,n);
    for(i=n-1;i;--i){
        j=query(0,1,1,n,i+1,a[i]);
        D[i]=D[j]+(j-i)+(n-a[i]);
        ans+=D[i];
    }
    printf("%lld\n",ans);
    for(i=1;i<=n;++i)st[i][1]=query(0,1,1,n,i+1,a[i]);
    st[n][1]=n;
    init(1,1,1,n);
    for(j=2;j<18;++j){
        for(i=1;i<n;++i){
            k=query(j-1,1,1,n,i+1,st[i][j-1]);
            st[i][j]=st[k][j-1];
        }
        st[n][j]=n;
        init(j,1,1,n);
    }
    for(;q--;){
        scanf("%d%d",&x,&y);
        int s=0;
        for(i=17;i;--i)if(a[st[x][i]]<y){
            s+=1<<(i-1);
            x=st[x][i];
        }
        if(a[x]<y)++s;
        printf("%d\n",s+1);
    }
    return 0;
}
