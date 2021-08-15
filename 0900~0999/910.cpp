#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int u,d;
    bool operator<(const data&r)const{
        if(u<d)return r.u<r.d?u<r.u:1;
        return r.u>r.d?d>r.d:0;
    }
}a[25010];
int D[25010],E[25010];
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d%d",&a[i].u,&a[i].d);
    sort(a+1,a+n+1);
    for(i=1;i<=n;++i)D[i]=D[i-1]+a[i].u;
    for(i=1;i<=n;++i)E[i]=max(D[i],E[i-1])+a[i].d;
    printf("%d",E[n]);
    return 0;
}
