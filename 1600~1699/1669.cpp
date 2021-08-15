#include <stdio.h>
#define M 1000000007
int main(){
    long long n;
    scanf("%lld",&n);
    printf("%lld",n*(n-1)%M*(n-2)%M*(n-3)%M);
    return 0;
}
