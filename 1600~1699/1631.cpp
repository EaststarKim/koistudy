#include <stdio.h>
int main(){
    long long a,b,s;
    scanf("%lld%lld",&a,&b);
    s=b-a;
    if(s<0)s=-s;
    if(a*b<0)--s;
    printf("%lld",s);
    return 0;
}
