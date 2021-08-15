#include <stdio.h>
int main()
{
    int w,h,x,y,t;
    scanf("%d%d%d%d%d",&w,&h,&x,&y,&t);
    x+=t;
    y+=t;
    if((x/w)%2)x=w-x%w;
    else x%=w;
    if((y/h)%2)y=h-y%h;
    else y%=h;
    printf("%d %d",x,y);
    return 0;
}
