#include <stdio.h>
int x[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},s;
int main(){
    int a,b,c,d,e,y=2000,m=1,D=1,t;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    s=144000*a+7200*b+360*c+20*d+e-2018843;
    for(;;){
        t=365+(y%4==0);
        if(s<t)break;
        s-=t,++y;
    }
    x[2]+=(y%4==0);
    for(;;){
        if(s<x[m])break;
        s-=x[m++];
    }
    printf("%d %d %d",y,m,D+s);
    return 0;
}
