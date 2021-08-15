#include <stdio.h>
int a[100010]={1,1,2};
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=3;i<=n;++i)a[i]=(a[i-1]+a[i-2]+3*a[i-3])%1000;
    printf("%d",a[n]);
    return 0;
}
