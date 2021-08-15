#include <stdio.h>
int a[1000010],mx;
int main()
{
    int i,n,k;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&k);
        a[k]=a[k-1]+1;
        if(mx<a[k])mx=a[k];
    }
    printf("%d",n-mx);
    return 0;
}
