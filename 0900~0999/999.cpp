#include <stdio.h>
int a[20]={0,2,11},b[20]={0,1,4};
int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=3;i<=n;++i){
        b[i]=a[i-1]+a[i-2]+b[i-1];
        a[i]=a[i-2]+2*b[i-1]+2*b[i];
    }
    printf("%d",a[n]);
    return 0;
}
