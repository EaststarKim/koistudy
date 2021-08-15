#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",n*(n+1)%4?n/2*(n/2+1):((n+1)/2)*((n+1)/2));
    return 0;
}
