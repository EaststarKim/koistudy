#include <stdio.h>
int main()
{
    long long a;
    int m,d,n;
    scanf("%lld%d%d%d",&a,&m,&d,&n);
    for(;n>1;--n,a=a*m+d);
    printf("%lld",a);
}
