#include <stdio.h>
#include <algorithm>
using namespace std;
int a[2223][2223],D[2223][2223];
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)for(j=1;j<=n;++j)scanf("%d",a[i]+j);
    for(i=2;i<=n;++i)a[i][0]=a[0][i]=-1e8;
    for(i=1;i<=n;++i)for(j=1;j<=n;++j)D[i][j]=min(D[i-1][j]+max(a[i][j]-a[i-1][j]+1,0),D[i][j-1]+max(a[i][j]-a[i][j-1]+1,0));
    printf("%d",D[n][n]-D[1][1]);
    return 0;
}
