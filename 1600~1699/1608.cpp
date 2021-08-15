#include <stdio.h>
int a[40]={1,1};
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;a[i++]<=n;++n)a[i]=a[i-1]+a[i-2];
    printf("%d",n);
    return 0;
}
