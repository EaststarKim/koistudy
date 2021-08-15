#include <stdio.h>
#include <queue>
using namespace std;
struct al{
    int e,t,nx;
}a[10010];
int st[1010],cnt;
void make_al(int s,int e,int t){a[++cnt]={e,t,st[s]},st[s]=cnt;}
struct data{
    int i,t;
    bool operator<(const data&r)const{
        return t>r.t;
    }
};
int d[1010],sum[1010],n,ans;
void dijk(int s){
    int i;
    for(i=1;i<=n;++i)d[i]=1e9;
    priority_queue<data> q;
    q.push({s,d[s]=0});
    while(!q.empty()){
        data p=q.top();q.pop();
        if(d[p.i]!=p.t)continue;
        for(i=st[p.i];i;i=a[i].nx)if(d[a[i].e]>p.t+a[i].t)q.push({a[i].e,d[a[i].e]=p.t+a[i].t});
    }
}
int main(){
    int i,m,k,s,e,t;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=m;++i){
        scanf("%d%d%d",&s,&e,&t);
        make_al(e,s,t);
    }
    dijk(k);
    for(i=1;i<=n;++i)ans=max(ans,d[i]);
    printf("%d",ans);
    return 0;
}
