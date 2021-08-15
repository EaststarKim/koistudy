#include <stdio.h>
int main(){
    int n,d,k;
    scanf("%d%d%d",&n,&d,&k);
    printf("%d.",n/d);
    n=n%d*10;
    for(;--k;){
        printf("%d",n/d);
        n=n%d*10;
    }
    printf("%d",n/d+(n%d*10/d>4));

    return 0;
}
