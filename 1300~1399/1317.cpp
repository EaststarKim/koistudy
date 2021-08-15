#include <stdio.h>
int main(){
    int n,a=1,b=0,t;
    scanf("%d",&n);
    for(;n--;)t=b,b=(b+a)%1000000007,a=t;
    printf("%d %d",a,b);
    return 0;
}
