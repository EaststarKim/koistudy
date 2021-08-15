#include <stdio.h>
int main()
{
    int i,n,t,f=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&t);
        if(t)++f;
    }
    if(n==f)printf("-1");
    else
    {
        for(i=1;i<=f-f%9;++i)printf("5");
        if(f<9)n=f+1;
        for(i=1;i<=n-f;++i)printf("0");
    }
    return 0;
}
