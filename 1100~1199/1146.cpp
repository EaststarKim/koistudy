#include <stdio.h>
int main(){
    int l,a,b,c,d;
    scanf("%d%d%d%d%d",&l,&a,&b,&c,&d);
    a=(a-1)/c+1,b=(b-1)/d+1;
    printf("%d",l-(a>b?a:b));
    return 0;
}
