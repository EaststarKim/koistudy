#include <stdio.h>
#include <math.h>
int main(){
    int r,h,s=0,t=1;
    scanf("%d%d",&r,&h);
    if(2*h/r>=1)s=1+2*h/r;
    if(2.0*h/r>=sqrt(3))t=3+(2.0*h/r-sqrt(3));
    printf("%d",s>t?s:t);
    return 0;
}
