#include <stdio.h>   
int a[1000010],cnt[25010];   
int main()   
{   
    int i,n,k,s,e;   
    scanf("%d%d",&n,&k);   
    for(i=1;i<=k;++i)   
    {   
        scanf("%d%d",&s,&e);   
        ++a[s];   
        --a[e+1];   
    }   
    for(i=1;i<=n;++i)a[i]+=a[i-1],++cnt[a[i]];   
    n=n/2+1;   
    for(i=0;i<=k;++i)   
    {   
        n-=cnt[i];   
        if(n<=0)   
        {   
            printf("%d",i);   
            return 0;   
        }   
    }   
}  