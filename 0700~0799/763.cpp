#include <stdio.h>
#include <math.h>
int main()
{
    int i,n,m;
    scanf("%d",&n);
    m=sqrt(n);
    for(i=2;i<=m;++i)
    {
        if(n%i)continue;
        while(n%i==0)
        {
            n/=i;
            printf("%d ",i);
        }
        m=sqrt(n);
    }
    if(n>1)printf("%d",n);
    return 0;
}
