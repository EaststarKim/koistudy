#include <stdio.h>
int main(){
    int i,n;
    scanf("%d",&n);
    if(n%3)puts("0");
    else{
        n/=3;
        for(i=1;n--;)i=i*2%100000007;
        printf("%d",i);
    }
    return 0;
}
