#include <stdio.h>
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",__builtin_popcount(a^b));
    return 0;
}
