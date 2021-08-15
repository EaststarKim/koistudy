#include <stdio.h>
int main()
{
    int n;
    long long ans=1;
    scanf("%d",&n);
    while(n)ans*=n--;
    printf("%lld",ans);
    return 0;
}
