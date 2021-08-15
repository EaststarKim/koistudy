#include <stdio.h>
int a[100010]={1,2,7};
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=3;i<=n;++i)a[i]=(3*a[i-1]+a[i-2]-a[i-3]+100007)%100007;
    printf("%d",a[n]);
    return 0;
}
