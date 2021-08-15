#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n%10)puts("-1");
    else{
        printf("%d ",n/300);
        n-=n/300*300;
        printf("%d ",n/60);
        n-=n/60*60;
        printf("%d",n/10);
    }
    return 0;
}
