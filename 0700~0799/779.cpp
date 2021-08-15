#include <stdio.h>
int a[97];
int main()
{
    int i,n,p,m,k;
    scanf("%d%d",&n,&p);
    k=n;
    for(i=0;i<=p;++i)
    {
        if(a[k*n%p])break;
        a[k*n%p]=a[k]+1;
        k=k*n%p;
    }
    printf("%d",a[k]-a[k*n%p]+1);
    return 0;
}
