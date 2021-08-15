#include <stdio.h>
long long a[10000010]={1,1,1,3};
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=4;i<=n;++i)a[i]=(a[i-1]*(i-1)+a[i-2])%100000007;
    printf("%d",((a[n]*(n-1)+a[n-1])%100000007*(n-1)+a[n])%100000007);
    return 0;
}
