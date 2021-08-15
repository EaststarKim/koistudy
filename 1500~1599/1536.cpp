#include <stdio.h>
int main(){
    int a,b,k;
    long long t=1;
    scanf("%d%d%d",&a,&b,&k);
    for(;b--;)t*=a;
    for(;--k;)t/=10;
    printf("%d",t%10);
    return 0;
}
