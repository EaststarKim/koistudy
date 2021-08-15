#include <stdio.h>
long long a[81]={1,1};
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=2;i<=n;++i)a[i]=a[i-1]+a[i-2];
    printf("%lld",a[n]-a[n/2]-(n%2?0:a[n/2-1]));
    return 0;
}
