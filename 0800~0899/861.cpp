#include <stdio.h>
typedef long long LL;
LL gcd(LL x,LL y){
    if(!y)return x;
    return gcd(y,x%y);
}
int main()
{
    int i,n,k;
    LL lcd=1;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&k);
        lcd=lcd*k/gcd(lcd,k);
    }
    printf("%lld",lcd);
    return 0;
}
