#include <stdio.h>
#include <math.h>
int main(){
    double x1,y1,x2,y2,t;
    scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
    if(x1>x2)t=x1,x1=x2,x2=t;
    if(y1>y2)t=y1,y1=y2,y2=t;
    long long w=floor(x2)-ceil(x1)+1,h=floor(y2)-ceil(y1)+1;
    printf("%lld",w*h);
    return 0;
}
