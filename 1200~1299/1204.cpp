#include <stdio.h>
int main(){
    int i,n,s=2,k=3;
    scanf("%d",&n);
    for(i=2;i<=n;k+=2-i%2,++i)s=s*2+k;
    printf("%d",s);
    return 0;
}
