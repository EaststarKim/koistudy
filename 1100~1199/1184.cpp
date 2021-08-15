#include <stdio.h>
int main(){
    long long n;
    scanf("%lld",&n);
    if(n%2)printf("%lld",(n+1)/2*n);
    else printf("%lld",n/2*(n+1));
    return 0;
}
