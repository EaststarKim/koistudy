#include <stdio.h>
int main()
{
    int a,b,c;
    scanf("%d.%d.%d",&a,&b,&c);
    printf("%04d.",a);
    printf("%02d.",b);
    printf("%02d",c);
}
