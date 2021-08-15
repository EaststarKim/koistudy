#include <stdio.h>
int x[100010];
int main()
{
    int i,w,n;
    scanf("%d%d",&w,&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&x[i]);
        x[i]+=x[i-1];
    }
    for(i=1;i<=n;++i)
    {
        if(i<5&&x[i]>w)break;
        if(i>4&&x[i]-x[i-4]>w)break;
    }
    printf("%d",i-1);
    return 0;
}
