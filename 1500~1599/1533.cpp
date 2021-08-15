#include <stdio.h>
#include <algorithm>
using namespace std;
struct al{
    int e,nx;
}a[200010];
int st[200010],cnt;
void make_al(int s,int e){a[++cnt]={e,st[s]},st[s]=cnt;}
int o[200010],lev[200010],s[200010],e[200010];
int q[200010],sl[200010],el[200010],t;
int sum[200010][26];
char c[200010];
void dfs(int p){
    int i;
    o[p]=s[p]=++t;
    for(i=st[p];i;i=a[i].nx){
        lev[a[i].e]=lev[p]+1;
        dfs(a[i].e);
    }
    e[p]=t;
}
void bfs(){
    int i,p,f=0,r=1;
    q[1]=1;
    while(f<r){
        p=q[++f];
        if(lev[q[f-1]]<lev[p])el[lev[p]-1]=f-1,sl[lev[p]]=f;
        for(i=st[p];i;i=a[i].nx)q[++r]=a[i].e;
    }
    el[lev[q[r]]]=r;
}
int main(){
    int i,j,k,n,m,p;
    scanf("%d%d",&n,&m);
    for(i=2;i<=n;++i){
        scanf("%d",&p);
        make_al(p,i);
    }
    scanf("%s",c+1);
    lev[1]=1;
    dfs(1);
    bfs();
    for(i=1;i<=n;++i){
        for(j=0;j<26;++j)sum[i][j]=sum[i-1][j];
        ++sum[i][c[q[i]]-97];
    }
    for(i=1;i<=n;++i)q[i]=o[q[i]];
    for(;m--;){
        scanf("%d%d",&p,&i);
        j=lower_bound(q+sl[i],q+el[i]+1,s[p])-q;
        k=upper_bound(q+sl[i],q+el[i]+1,e[p])-q-1;
        int t=0;
        for(i=0;i<26;++i)t+=(sum[k][i]-sum[j-1][i])%2;
        puts(t<2?"Yes":"No");
    }
    return 0;
}
