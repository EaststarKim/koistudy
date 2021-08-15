#include <stdio.h>
struct data{
    int e,nx;
}a[200010];
int st[100010],cnt;
void make_al(int s,int e){a[++cnt]={e,st[s]},st[s]=cnt;}
int lev[100010],s[100010][21],t[100010][21],ans[100010],k;
void f(int p){
    int i,j,sum=0;
    for(i=st[p];i;i=a[i].nx)if(!lev[a[i].e]){
        lev[a[i].e]=lev[p]+1;
        f(a[i].e);
        for(j=1;j<=k;++j)s[p][j]+=s[a[i].e][j-1];
    }
}
void g(int p,int q){
    int i,j;
    for(i=1;i<=k;++i)s[q][i]+=s[p][i-1];
    for(i=0;i<=k;++i)ans[q]+=s[q][i];
    for(i=st[q];i;i=a[i].nx)if(lev[q]<lev[a[i].e]){
        for(j=0;j<k;++j)s[q][j+1]-=s[a[i].e][j],t[a[i].e][j]=s[a[i].e][j];
        g(q,a[i].e);
        for(j=0;j<k;++j)s[q][j+1]+=t[a[i].e][j];
    }
}
int main(){
    int i,j,n,x,y;
    scanf("%d%d",&n,&k);
    for(i=1;i<n;++i){
        scanf("%d%d",&x,&y);
        make_al(x,y);
        make_al(y,x);
    }
    for(i=1;i<=n;++i)scanf("%d",s[i]);
    lev[1]=1;
    f(1);
    for(i=0;i<=k;++i)ans[1]+=s[1][i];
    for(i=st[1];i;i=a[i].nx){
        for(j=0;j<k;++j)s[1][j+1]-=s[a[i].e][j],t[a[i].e][j]=s[a[i].e][j];
        g(1,a[i].e);
        for(j=0;j<k;++j)s[1][j+1]+=t[a[i].e][j];
    }
    for(i=1;i<=n;++i)printf("%d\n",ans[i]);
    return 0;
}
