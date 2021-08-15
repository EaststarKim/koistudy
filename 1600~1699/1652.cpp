#include <stdio.h>
int a[210]={0,1};
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=2;i<=n;++i)a[i]=(a[i-1]+a[i-2])%10009;
    printf("%d",a[n]);
    return 0;
}
