#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int s,e;
}edge[300010];
struct al{
    int e,nx;
}a[600010];
int st[300010],cnt;
void make_al(int s,int e){a[++cnt]={e,st[s]},st[s]=cnt;}
int lev[300010],spt[300010][19];
void dfs(int p){
    int i;
    for(i=1;i<19;++i)spt[p][i]=spt[spt[p][i-1]][i-1];
    for(i=st[p];i;i=a[i].nx)if(!lev[a[i].e]){
        lev[a[i].e]=lev[p]+1;
        spt[a[i].e][0]=p;
        dfs(a[i].e);
    }
}
int g[300010],d[300010],x[300010],y[300010],ans[300010];
int seek(int n){return g[n]==n?n:g[n]=seek(g[n]);}
void uf(int a,int b,int nd,int nx,int ny){
    if(lev[a]<lev[b])g[b]=a,d[a]=nd,x[a]=nx,y[a]=ny;
    else g[a]=b,d[b]=nd,x[b]=nx,y[b]=ny;
}
int LCA(int a,int b){
    int i;
    if(lev[a]<lev[b])swap(a,b);
    for(i=18;i>=0;--i)if(lev[a]-lev[b]>=1<<i)a=spt[a][i];
    if(a==b)return a;
    for(i=18;i>=0;--i)if(spt[a][i]!=spt[b][i])a=spt[a][i],b=spt[b][i];
    return spt[a][0];
}
int dis(int a,int b){
    int lca=LCA(a,b);
    return lev[b]+lev[a]-lev[lca]*2;
}
int main(){
    int i,n,s,e;
    scanf("%d",&n);
    for(i=1;i<n;++i){
        scanf("%d%d",&s,&e);
        edge[i]={s,e};
        make_al(s,e);
        make_al(e,s);
    }
    lev[1]=1;
    dfs(1);
    for(i=1;i<=n;++i)g[i]=i,x[i]=y[i]=i;
    for(i=n;--i;){
        s=seek(edge[i].s),e=seek(edge[i].e);
        ans[i]=ans[i+1]-d[s]-d[e];
        int d1=d[s],d2=d[e],d3,mx;
        int sx=dis(edge[i].s,x[s]),sy=dis(edge[i].s,y[s]),ex=dis(edge[i].e,x[e]),ey=dis(edge[i].e,y[e]);
        d3=max(sx,sy)+max(ex,ey)+1;
        mx=max(d1,max(d2,d3));
        ans[i]+=mx;
        if(mx==d1)uf(s,e,d1,x[s],y[s]);
        else if(mx==d2)uf(s,e,d2,x[e],y[e]);
        else uf(s,e,d3,sx>sy?x[s]:y[s],ex>ey?x[e]:y[e]);
    }
    for(i=1;i<=n;++i)printf("%d
",ans[i]);
    return 0;
}
