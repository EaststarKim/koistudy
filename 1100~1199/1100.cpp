#include <stdio.h>
int main()
{
    int n;
    long long i,m,t,s=1;
    scanf("%d%lld",&n,&m);
    t=n;
    for(i=1;i<=m;i*=2){
        if(m&i)s=(s*t)%10000007;
        t=(t*t)%10000007;
    }
    printf("%d",s);
    return 0;
}
