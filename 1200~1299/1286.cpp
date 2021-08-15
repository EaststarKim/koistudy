#include <stdio.h>
long long n,m,k=1,s=7,t=4,M=1000000007;
int main(){
    scanf("%d",&n);
    for(m=n;m;m/=2,s=(s*s)%M)if(m&1)k=(k*s)%M;
    for(n=n*(n-1);n;n/=2,t=(t*t)%M)if(n&1)k=(k*t)%M;
    printf("%d",k);
    return 0;
}
