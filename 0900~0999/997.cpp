#include <stdio.h>
int main()
{
    int i,n,p,k,t;
    scanf("%d%d%d",&n,&p,&k);
    t=p-k;
    if(t>1)printf("<< ");
    else t=1;
    for(i=t;i<p;++i)printf("%d ",i);
    printf("(%d)",p);
    for(i=p+1;i<=p+k&&i<=n;++i)printf(" %d",i);
    if(p+k<n)printf(" >>");
    return 0;
}
