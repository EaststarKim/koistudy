#include <stdio.h>
int main(){
    int n,t=1,s=0;
    scanf("%d",&n);
    for(;t<=n;t*=10)s+=n/t%10;
    printf("%d",t/9*s);
    return 0;
}
