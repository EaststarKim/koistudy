#include <stdio.h>
#include <stdlib.h>
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
    int n,m,p;
    scanf("%d%d%d",&n,&m,&p);
    printf("%d",(p*m-gcd(n,m)-abs(gcd(n-p,m))-p)/2+1);
    return 0;
}
