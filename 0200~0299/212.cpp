#include <stdio.h>   
int main()   
{   
    int c,h,o,n,cl;   
    scanf("%d%d%d%d%d",&c,&h,&o,&n,&cl);   
    if((c*4+h+o*6+n*5+cl*7)%8)printf("Impossible");   
    else printf("Possible");   
    return 0;   
}