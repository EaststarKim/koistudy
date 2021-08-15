#include <stdio.h>
long long n,m=1,t=2,M=1000000007;
int main(){
    scanf("%d",&n);
    for(n=n*(n-1)/2;n;n/=2,t=(t*t)%M)if(n&1)m=(m*t)%M;
    printf("%d",m);
    return 0;
}
