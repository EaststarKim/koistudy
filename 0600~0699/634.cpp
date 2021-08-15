#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int i;
    double x,y;
    bool operator<(const data&r)const{
        return x<r.x;
    }
}a[3010];
int ans[3010],chk[3010],t;
int main(){
    int i,n;
    scanf("%d",&n);
    scanf("%lf%lf",&a[0].x,&a[0].y);
    for(i=1;i<=n;++i)scanf("%lf%lf",&a[i].x,&a[i].y),a[i].i=i;
    sort(a,a+n+1);
    ++t;
    for(i=1;i<n;++i)if((a[i].y-a[0].y)*(a[n].x-a[0].x)>(a[n].y-a[0].y)*(a[i].x-a[0].x))ans[t++]=i,chk[i]=1;
    ans[t++]=n;
    for(;--i;)if(!chk[i])ans[t++]=i;
    for(i=0;i<t;++i)if(!a[ans[i]].i)break;
    for(;a[ans[i=(i+1)%t]].i;)printf("%d ",a[ans[i]].i);
    return 0;
}
