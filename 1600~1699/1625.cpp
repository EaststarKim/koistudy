#include <stdio.h>
#include <algorithm>
int main(){
    int n,x;
    scanf("%d%d",&n,&x);
    printf("%d",3*(n-std::__gcd(n,x)));
    return 0;
}
