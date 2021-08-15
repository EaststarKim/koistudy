#include <stdio.h>
#define M 1000000007
int main(){
    long long a,b;
    int i,ans=0;
    scanf("%lld%lld",&a,&b);
    for(i=1;i<b;++i)ans=(ans+(((a*(a+1)/2%M)*i)%M)*b+a*i)%M;
    printf("%d",ans);
    return 0;
}
