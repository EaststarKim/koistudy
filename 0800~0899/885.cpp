#include <stdio.h>
int main()
{
    int i;
    double s,e,t=0,m=0;
    for(i=1;i<6;++i){
        scanf("%lf%lf",&s,&e);
        e-=s;
        if(e>5)e=5;
        if(e<=1)e=0;
        else e-=1;
        t+=e;
        m+=e*1e4;
    }
    if(t<=5)m*=1.05;
    if(t>=15)m*=0.95;
    printf("%g",m);
    return 0;
}
