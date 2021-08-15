#include <stdio.h>
int main(){
    int t,n;
    long long i,s;
    scanf("%d",&t);
    for(;t--;){
        scanf("%d",&n);
        s=(long long)n*(n+1)/2;
        for(i=1;i<=n;i*=2);
        s-=(i-1)*2;
        printf("%lld\n",s);
    }
    return 0;
}
