#include <stdio.h>
int a[31]={0,0,3},b[31]={0,0,2};
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=4;i<=n;i+=2)b[i]=b[i-2]+a[i-2]*2,a[i]=a[i-2]+b[i];
    printf("%d",a[n]);
    return 0;
}
