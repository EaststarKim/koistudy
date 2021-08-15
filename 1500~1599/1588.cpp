#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int a[2][1010][1010],D[1010][1010];
int x[]={0,-1,-1,0,1,1,1,0,-1},y[]={0,0,1,1,1,0,-1,-1,-1};
int main(){
    int i,j,l,n,m,k,r,c;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)scanf("%d",a[0][i]+j),a[1][i][j]=a[0][i][j];
    }
    for(i=1;i<=k;++i){
        scanf("%d%d",&r,&c);
        for(j=0;j<9;++j)a[0][r+x[j]][c+y[j]]=-1;
        for(j=0;j<9;++j)a[1][r+x[j]][c+1+y[j]]=-1;
    }
    for(i=0;i<=n;++i){
        for(j=0;j<=m;++j)D[i][j]=1e9;
    }
    D[1][1]=a[0][1][1];
    for(i=3;i<=n+m;++i){
        for(j=max(1,i-m);j<=n&&j<i;++j)if(a[i%2][j][i-j]>=0)D[j][i-j]=min(D[j-1][i-j],D[j][i-j-1])+a[i%2][j][i-j];
    }
    if(D[n][m]>=1e9)D[n][m]=-1;
    printf("%d",D[n][m]);
    return 0;
}
