#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
struct al{
    int e,t,nx;
}a[400010];
int st[100010],cnt;
void make_al(int s,int e,int t){a[++cnt]={e,t,st[s]},st[s]=cnt;}
struct data{
    int i,d;
    bool operator<(const data&r)const{
        return d>r.d;
    }
}b[100010];
int d[100010];
priority_queue<data> pq;
void dijkstra(){
    int i;
    while(!pq.empty()){
        data t=pq.top();
        pq.pop();
        if(d[t.i]!=t.d)continue;
        for(i=st[t.i];i;i=a[i].nx)if(d[a[i].e]>t.d+a[i].t)pq.push({a[i].e,d[a[i].e]=t.d+a[i].t});
    }
}
int g[100010];
int seek(int n){return g[n]==n?n:g[n]=seek(g[n]);}
int lev[100010],spt[100010][17];
void trace(int s){
    int i;
    if(!s||lev[s])return;
    trace(spt[s][0]);
    lev[s]=lev[spt[s][0]]+1;
    for(i=0;i<16;++i)spt[s][i+1]=spt[spt[s][i]][i];
}
int lca(int x,int y){
    int i;
    if(lev[x]>lev[y])swap(x,y);
    for(i=17;i--;)if(lev[y]-(1<<i)>=lev[x])y=spt[y][i];
    if(x==y)return x;
    for(i=17;i--;)if(spt[x][i]!=spt[y][i])x=spt[x][i],y=spt[y][i];
    return spt[x][0];
}
int main(){
    int i,j,n,m,k,q,s,e,t;
    scanf("%d%d%d%d",&n,&m,&k,&q);
    for(i=1;i<=m;++i){
        scanf("%d%d%d",&s,&e,&t);
        make_al(s,e,t);
        make_al(e,s,t);
    }
    for(i=1;i<=n;++i)d[i]=1e9;
    for(i=1;i<=k;++i){
        scanf("%d",&s);
        pq.push({s,d[s]=0});
    }
    dijkstra();
    for(i=1;i<=n;++i)b[i]={i,d[i]},g[i]=i;
    sort(b+1,b+n+1);
    for(i=1;i<=n;++i){
        s=seek(b[i].i);
        for(j=st[b[i].i];j;j=a[j].nx){
            e=seek(a[j].e);
            if(s==e||d[s]>d[e])continue;
            g[e]=spt[e][0]=s;
        }
    }
    for(i=1;i<=n;++i)if(!lev[i])trace(i);
    for(;q--;){
        scanf("%d%d",&s,&e);
        printf("%d\n",d[lca(s,e)]);
    }
    return 0;
}
