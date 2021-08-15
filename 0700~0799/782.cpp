#include <stdio.h>
int a[20]={1,2,4},b[20]={1,1,1};
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=3;i<=n;++i)
    {
        b[i]=b[i-1]+b[i-3];
        a[i]=b[i]*b[i]*b[i];
        for(j=1;j<=i;++j)a[i]+=a[j-1]*b[i-j]*b[i-j]*b[i-j];
    }
    printf("%d",a[n]);
    return 0;
}
