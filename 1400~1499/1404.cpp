#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
struct data{
    int s,e;
    bool operator<(const data&r)const{
        return s<r.s;
    }
}a[2000010];
struct que{
    int s,d;
    bool operator<(const que&r)const{
        return d>r.d;
    }
}t;
priority_queue<que> q;
int st[3510],d[3510],n,m;
int main(){
    int i,s,e;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i){
        scanf("%d%d",&a[i].s,&a[i].e);
        a[m+i]=a[i];
        swap(a[m+i].s,a[m+i].e);
    }
    m*=2;
    sort(a+1,a+m+1);
    for(i=1;i<=m;++i)if(a[i].s!=a[i-1].s)st[a[i].s]=i;
    scanf("%d%d",&s,&e);
    q.push({s,0});
    for(i=1;i<=n;++i)d[i]=1e9;
    d[s]=0;
    while(!q.empty()){
        t=q.top();
        q.pop();
        if(t.s==e){
            printf("%d",d[e]);
            return 0;
        }
        if(t.d!=d[t.s])continue;
        for(i=st[t.s];a[i].s==t.s;++i)if(d[a[i].e]>d[a[i].s]+1){
            d[a[i].e]=d[a[i].s]+1;
            q.push({a[i].e,d[a[i].e]});
        }
    }
    puts("0");
    return 0;
}
