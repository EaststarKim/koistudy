#include <stdio.h>
int main()
{
    int a,b;
    scanf("%dx^%d",&a,&b);
    printf("%lldx^%d",(long long)a*b,b-1);
    return 0;
}
