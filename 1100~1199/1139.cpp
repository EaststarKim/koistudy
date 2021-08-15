#include <stdio.h>
#include <algorithm>
using namespace std;
int a[50][50],D[50][50];
int main(){
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    --m;
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)scanf("%1d",a[i]+j),a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        for(j=2;j<=m;++j)D[i][j]=1e9;
        D[i][1]=a[i][i];

    }
    for(i=3;i<=n;++i){
        for(j=2;j<i;++j){
            for(k=1;k<j&&k<m;++k)D[i][k+1]=min(D[i][k+1],D[j][k]+a[i][i]-a[j-1][i]-a[i][j-1]+a[j-1][j-1]);
        }
    }
    printf("%d",D[n][m]);
    return 0;
}
