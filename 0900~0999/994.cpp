#include <stdio.h>
#include <algorithm>
int main()
{
    long long a[3];
    scanf("%lld%lld%lld",a,a+1,a+2);
    std::sort(a,a+3);
    printf("%lld",a[1]);
    return 0;
}
