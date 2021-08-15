#include <stdio.h>
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
    int w,h;
    scanf("%d%d",&w,&h);
    printf("%d",w+h-gcd(w,h));
    return 0;
}
