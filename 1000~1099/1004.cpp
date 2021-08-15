#include <stdio.h>
int main()
{
    long long k,n,m;
    scanf("%lld%lld%lld",&k,&n,&m);
    k*=n;
    if(k<m)k=m;
    printf("%lld",k-m);
    return 0;
}
