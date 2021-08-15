#include <stdio.h>
long long a,b,c,M=1e18;
int main(){
    scanf("%lld%lld",&a,&b);
    --M;
    while(a){
        if(a%2)c+=b;
        a>>=1,b<<=1;
        b%=M,c%=M;
    }
    printf("%lld",c);
    return 0;
}
