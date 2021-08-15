#include <stdio.h>
int a[3][60];
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d%d",&a[0][i],&a[1][i]);
        for(j=1;j<i;++j)
        {
            if(a[0][i]<a[0][j]&&a[1][i]<a[1][j])++a[2][i];
            if(a[0][i]>a[0][j]&&a[1][i]>a[1][j])++a[2][j];
        }
    }
    for(i=1;i<=n;++i)printf("%d ",a[2][i]+1);
    return 0;
}
