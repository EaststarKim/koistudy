#include <stdio.h>
int main(){
    long long n,t,r;
    scanf("%lld%lld",&n,&t);
    r=n%(t-1);
    printf("%lld",(n*n-r*r)/(t-1)*(t-2)/2+r*(r-1)/2);
    return 0;
}
