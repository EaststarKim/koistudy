#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct data{
    int s,e,d;
    bool operator<(const data&r)const{
        return s<r.s;
    }
}a[400010];
int st[200010],q[200010],d[200010],n,m;
int bfs(int p){
    int i,f=0,r=1,mx=0,mi;
    memset(d,0,sizeof d);
    q[1]=p;
    d[p]=1;
    while(f<r){
        p=q[++f];
        for(i=st[p];a[i].s==p;++i)if(!d[a[i].e]){
            d[a[i].e]=d[p]+a[i].d;
            q[++r]=a[i].e;
        }
    }
    for(i=1;i<=n;++i)if(mx<d[i])mx=d[i],mi=i;
    return mi;
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<n;++i)scanf("%d%d%d",&a[i].s,&a[i].e,&a[i].d),a[n+i-1]=a[i],swap(a[n+i-1].s,a[n+i-1].e);
    m=n*2-1;
    sort(a+1,a+m);
    for(i=1;i<m;++i)if(a[i].s!=a[i-1].s)st[a[i].s]=i;
    printf("%d",d[bfs(bfs(1))]-1);
    return 0;
}
