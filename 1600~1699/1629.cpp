#include <stdio.h>
#include <algorithm>
int main(){
    long long n,x;
    scanf("%lld%lld",&n,&x);
    printf("%lld",3*(n-std::__gcd(n,x)));
    return 0;
}
