#include <stdio.h>
using namespace std;
struct al{
    int e,nx;
}a[100010],b[100010],c[100010];
int sta[10010],stb[10010],stc[10010],an,bn,cn;
void make_al(al *a,int &cnt,int *st,int s,int e){a[++cnt]={e,st[s]},st[s]=cnt;}
int n,m,s,e;
int stck[10010],chk[10010],t;
void dfs(int p){
    int i;
    chk[p]=1;
    for(i=sta[p];i;i=a[i].nx)if(!chk[a[i].e])dfs(a[i].e);
    stck[++t]=p;
}
int g[10010],sz[10010],in[10010],D[10010],gn;
void scc(int p){
    int i;
    ++sz[g[p]=gn];
    for(i=stb[p];i;i=b[i].nx)if(!g[b[i].e])
        scc(b[i].e);
}
int main(){
    int i,j,x,y;
    scanf("%d%d%d%d",&n,&m,&s,&e);
    for(i=1;i<=m;++i){
        scanf("%d%d",&x,&y);
        make_al(a,an,sta,x,y);
        make_al(b,bn,stb,y,x);
    }
    for(i=1;i<=n;++i)if(!chk[i])dfs(i);
    for(i=n;i;--i)if(!g[stck[i]])++gn,scc(stck[i]);
    for(i=1;i<=n;++i){
        for(j=sta[i];j;j=a[j].nx)if(g[i]!=g[a[j].e]){
            make_al(c,cn,stc,g[i],g[a[j].e]),++in[g[a[j].e]];
        }
    }
    s=g[s],e=g[e];
    D[s]=sz[s];
    for(;;){
        for(i=1;i<=gn;++i)if(!in[i])break;
        if(i>gn)break;
        in[i]=-1;
        for(j=stc[i];j;j=c[j].nx){
            if(D[i])D[c[j].e]=max(D[c[j].e],D[i]+sz[c[j].e]);
            --in[c[j].e];
        }
    }
    printf("%d",D[e]);
    return 0;
}
