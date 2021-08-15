#include <stdio.h>
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
    int t,a,b;
    scanf("%d",&t);
    for(;t--;){
        scanf("%d%d",&a,&b);
        a+=60,b+=60;
        if(a!=b)a=a*1440/gcd(a-b,1440);
        if(a<0)a=-a;
        a%=1440;
        printf("%02d:%02d\n",a/60,a%60);
    }
    return 0;
}
