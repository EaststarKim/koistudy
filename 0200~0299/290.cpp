#include <stdio.h>
int d[10010]={1},mx;
int main()
{
    int i,j,n,w,k,c;
    scanf("%d%d",&w,&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d%d",&c,&k);
        for(j=0;j<=w-k;++j)
        {
            if(d[j]&&d[j+k]<d[j]+c)d[j+k]=d[j]+c;
        }
    }
    for(i=0;i<=w;++i)
    {
        if(mx<d[i])mx=d[i];
    }
    printf("%d",mx-1);
    return 0;
}