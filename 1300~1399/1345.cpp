#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
struct data{
    int s,e,d;
    bool operator<(const data&r)const{
        return s<r.s;
    }
}a[2910];
struct que{
    int s,d;
    bool operator<(const que&r)const{
        return d>r.d;
    }
};
int st[810],c[510],chk[810],n,p,ans=1e9;
void dijk(int s){
    int i,d,sum=0,cnt;
    for(i=1;i<=p;++i)chk[i]=1e9;
    priority_queue<que> q;
    q.push({s,0});
    chk[s]=0;
    while(!q.empty()){
        s=q.top().s,d=q.top().d;
        q.pop();
        if(chk[s]!=d)continue;
        for(i=st[s];a[i].s==s;++i)if(chk[a[i].e]>d+a[i].d)chk[a[i].e]=d+a[i].d,q.push({a[i].e,chk[a[i].e]});
    }
    for(i=1;i<=n;++i)sum+=chk[c[i]];
    ans=min(ans,sum);
}
int main(){
    int i,j,k,m,s,e,d;
    scanf("%d%d%d",&n,&p,&m);
    for(i=1;i<=n;++i)scanf("%d",c+i);
    for(i=1;i<=m;++i)scanf("%d%d%d",&s,&e,&d),a[i]={s,e,d},a[m+i]={e,s,d};
    m*=2;
    sort(a+1,a+m+1);
    for(i=1;i<=m;++i)if(a[i].s!=a[i-1].s)st[a[i].s]=i;
    for(i=1;i<=p;++i)dijk(i);
    printf("%d",ans);
    return 0;
}
