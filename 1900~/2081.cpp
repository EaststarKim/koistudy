#include <stdio.h>
#include <algorithm>
#include <queue>
#define f first
#define s second
using namespace std;
typedef pair<int,int> data;
data a[30010];
int st[30010],D[30010];
priority_queue<data,vector<data>,greater<data> > q;
int main(){
    int i,j,n,m,s,e,d;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;++i)scanf("%d%d",&a[i].f,&a[i].s);
    s=a[0].f,e=a[1].f;
    sort(a,a+m);
    st[a[0].f]=0;
    for(i=1;i<m;++i)if(a[i].f!=a[i-1].f)st[a[i].f]=i;
    for(i=0;i<n;++i)D[i]=2e9;
    D[s]=0;
    q.push({0,s});
    while(!q.empty()){
        data p=q.top();
        q.pop();
        if(D[p.s]!=p.f)continue;
        for(i=st[p.s];a[i].f==p.s&&i<m;++i){
            d=p.f;
            for(j=p.s+a[i].s;j<n;j+=a[i].s)if(D[j]>++d)q.push({D[j]=d,j});
            d=p.f;
            for(j=p.s-a[i].s;j>=0;j-=a[i].s)if(D[j]>++d)q.push({D[j]=d,j});
        }
    }
    printf("%d",D[e]<2e9?D[e]:-1);
    return 0;
}
