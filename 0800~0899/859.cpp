#include <stdio.h>
int i,n,s;
int main(){
    scanf("%d",&n);
    for(;n;i=n%i?n:i,n-=n/i,s+=i-1)for(i=2;i*i<=n&&n%i;++i);
    printf("%d",s);
    return 0;
}
