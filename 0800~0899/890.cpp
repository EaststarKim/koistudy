#include <stdio.h>
#define min(a,b) a<b? a:b
int a[1010][1010];
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)scanf("%d",a[i]+j);
    }
    for(i=2;i<=n;++i)a[0][i]=a[i][0]=2e9;
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)a[i][j]+=min(a[i-1][j],a[i][j-1]);
    }
    printf("%d",a[n][n]);
    return 0;
}
