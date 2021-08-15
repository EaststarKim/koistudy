#include <stdio.h>
int a[40]={1,1};
int main(){
    int i,n,k;
    scanf("%d%d",&n,&k);
    for(i=2;i<n;++i)a[i]=a[i-1]+a[i-2];
    printf("%d",a[k-1]*a[n-k]);
    return 0;
}
