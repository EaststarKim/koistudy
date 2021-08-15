#include <stdio.h>
int main()
{
    int i,y,k,n,sw=0;
    scanf("%d%d%d",&y,&k,&n);
    for(i=0;i<=n;i+=k)
    {
        if(y<i)
        {
            sw=1;
            printf("%d ",i-y);
        }
    }
    if(!sw)printf("-1");
    return 0;
}
