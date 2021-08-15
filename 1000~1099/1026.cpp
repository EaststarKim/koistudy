#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1000010],mx;
long long s;
int main()
{
    int i,n,t;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i<=n;++i){
        t=max(a[i-1]-a[i]+1,mx-a[i]);
        if(t>0)s+=t,a[i]+=t;
        mx=max(mx,a[i-1]);
    }
    printf("%lld",s);
    return 0;
}
