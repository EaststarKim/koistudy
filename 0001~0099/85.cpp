#include <stdio.h>
int main()
{
    int w,h,b;
    scanf("%d%d%d",&w,&h,&b);
    printf("%.2f MB",(float)w*h*b/8388608);
}
