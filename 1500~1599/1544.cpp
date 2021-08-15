#include <stdio.h>
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d",gcd(a,gcd(b,c)));
    return 0;
}
