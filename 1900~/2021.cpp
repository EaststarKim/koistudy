#include <stdio.h>
int main(){
    long long a,b,s=0;
    scanf("%lld%lld",&a,&b);
    if(a<=2&&2<=b)s-=2;
    a=(a+1)/2,b/=2;
    s+=b*(b+1)-a*(a-1);
    printf("%lld",s);
    return 0;
}
