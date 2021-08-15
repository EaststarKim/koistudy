#include <stdio.h>
int a[1000001]={1,2};
int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=2;i<n;++i)a[i]=(a[i-1]+i*a[i-2])%2014;
    printf("%d",a[n-1]);
    return 0;
}
