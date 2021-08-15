#include <stdio.h>
int main()
{
    int i,t,k;
    long long n,m,d;
    scanf("%d",&t);
    for(i=1;i<=t;++i){
        scanf("%lld%lld%d%lld",&n,&m,&k,&d);
        printf("Case %d: ",i);
        if(m<0)m=-m;
        if((m-n)*k>d*24)puts("No");
        else puts("Yes");
    }
    return 0;
}
