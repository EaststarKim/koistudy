#include <stdio.h>
int f(long long n){return n?f(n/10)+(n%10==5):0;}
int main(){
    int k,r;
    long long n,t=1;
    scanf("%lld%d",&n,&k);
    for(++n;f(n)<k;){
        r=n/t%10;
        r==5?t*=10:r<5?n+=(5-r)*t:n+=t;
    }
    printf("%lld",n);
    return 0;
}
