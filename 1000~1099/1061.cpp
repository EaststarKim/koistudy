#include <stdio.h>
long long a[10010]={1,1,2,4,7,13,23};
int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=7;i<=n;++i)a[i]=(a[i-1]+a[i-2]+a[i-5]+2*a[i-6]+a[i-7])%1000000007;
    printf("%d",a[n]);
    return 0;
}
