#include <stdio.h>
#include <queue>
using namespace std;
struct al{
    int nx,e,t;
}a[100010];
struct data{
    int i,j;
    long long d;
    bool operator<(const data&r)const{
        return d>r.d;
    }
};
int st[10010],cnt;
void make_al(int s,int e,int t){a[++cnt]={st[s],e,t},st[s]=cnt;}
long long d[10010][21],ans=1e18;
priority_queue<data> q;
int main(){
    int i,j,n,m,k,s,e,t;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=m;++i){
        scanf("%d%d%d",&s,&e,&t);
        make_al(s,e,t);
        make_al(e,s,t);
    }
    for(i=2;i<=n;++i){
        for(j=0;j<=k;++j)d[i][j]=1e18;
    }
    q.push({1,0,0});
    while(!q.empty()){
        s=q.top().i;
        j=q.top().j;
        t=q.top().d;
        q.pop();
        if(t!=d[s][j])continue;
        for(i=st[s];i;i=a[i].nx){
            if(d[a[i].e][j]>t+a[i].t)q.push({a[i].e,j,d[a[i].e][j]=t+a[i].t});
            if(j<k&&d[a[i].e][j+1]>t)q.push({a[i].e,j+1,d[a[i].e][j+1]=t});
        }
    }
    for(i=0;i<=k;++i)ans=min(ans,d[n][i]);
    printf("%lld",ans);
    return 0;
}
