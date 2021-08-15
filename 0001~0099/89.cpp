#include <stdio.h>
int main()
{
    int r,n;
    long long a;
    scanf("%lld%d%d",&a,&r,&n);
    for(;n>1;--n,a*=r);
    printf("%lld",a);
}
