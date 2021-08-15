#include <stdio.h>
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main()
{
    int a,b,c,d;
    scanf("%d%d%d",&a,&b,&c);
    d=gcd(gcd(a,b),c);
    printf("%d",a*b*c/gcd(a,b)/gcd(b,c)/gcd(c,a)*d);
}
