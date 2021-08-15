#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int s,t;
    bool operator<(const data&r)const{
        return s>r.s;
    }
}a[50010];
int main(){
    int i,n,k;
    long long ans=0;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;++i)scanf("%d%d",&a[i].s,&a[i].t);
    sort(a+1,a+n+1);
    for(i=1;i<=n&&k;++i){
        if(a[i].s<1)break;
        if(a[i].t<k)k-=a[i].t,ans=(ans+a[i].s*a[i].t);
        else ans=(ans+a[i].s*k),k=0;
    }
    printf("%lld",ans);
    return 0;
}
