#include <stdio.h>
int main(){
    int n;
    double s=0;
    scanf("%d",&n);
    for(;n--;)s+=(double)(1-n%2*2)/(n*2+1);
    printf("%lf",s*4);
    return 0;
}
