#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int e,t,nx;
}a[200010];
int st[100010],cnt;
void make_al(int s,int e,int t){a[++cnt]={e,t,st[s]},st[s]=cnt;}
int g[100010],d[100010],mx1[100010],mx2[100010],ans;
void dfs(int s){
    int i;
    g[s]=cnt;
    mx1[s]=mx2[s]=d[s];
    for(i=st[s];i;i=a[i].nx)if(!g[a[i].e]){
        d[a[i].e]=d[s]+a[i].t;
        dfs(a[i].e);
        if(mx1[s]<mx1[a[i].e])mx2[s]=mx1[s],mx1[s]=mx1[a[i].e];
        else mx2[s]=max(mx2[s],mx1[a[i].e]);
    }
    ans=max(ans,mx1[s]+mx2[s]-d[s]*2);
}
int vis[100010],r[100010];
void f(int s,int t){
    int i;
    r[g[s]]=max(mx1[s]-d[s],t);
    t=max(t,mx2[s]-d[s]);
    for(i=st[s];i;i=a[i].nx)if(d[s]<d[a[i].e]){
        if(mx1[s]==mx1[a[i].e]){
            if(t+a[i].t<r[g[s]])f(a[i].e,t+a[i].t);
            else break;
        }
    }
}
int main(){
    int i,n,m,l,s,e,t;
    scanf("%d%d%d",&n,&m,&l);
    for(i=1;i<=m;++i){
        scanf("%d%d%d",&s,&e,&t);
        ++s,++e;
        make_al(s,e,t);
        make_al(e,s,t);
    }
    cnt=0;
    for(i=1;i<=n;++i)if(!g[i])++cnt,dfs(i);
    for(i=1;i<=n;++i)if(!vis[g[i]])vis[g[i]]=1,f(i,mx2[i]);
    sort(r+1,r+cnt+1);
    if(cnt>1)ans=max(ans,r[cnt-1]+r[cnt]+l);
    if(cnt>2)ans=max(ans,r[cnt-2]+r[cnt-1]+l*2);
    printf("%d",ans);
    return 0;
}
