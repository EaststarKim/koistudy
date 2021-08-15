#include <stdio.h>
#include <math.h>
int main(){
    int i,cnt=0;
    long long n,m;
    scanf("%lld",&n);
    for(;n>1;++cnt){
        m=sqrt(n);
        i=2;
        if(n%2)for(i=3;i<=m&&n%i;++i);
        if(i>m)i=n;
        n=n/i*(i-1);
    }
    printf("%d",cnt);
    return 0;
}
