#include <stdio.h>
int main()
{
    int a,b,c;
    scanf("%d.%d.%d",&a,&b,&c);
    printf("%02d-",c);
    printf("%02d-",b);
    printf("%04d",a);
}
