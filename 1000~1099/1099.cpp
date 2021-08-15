#include <stdio.h>
int main()
{
    int n,m;
    long long t=1;
    scanf("%d%d",&n,&m);
    while(m--)t=(t*n)%1000000007;
    printf("%d",t);
    return 0;
}
