#include <stdio.h>
#include <algorithm>
using namespace std;
int a[2010],D[4][2010][2010][3],ans;
int main()
{
    int i,j,l,n,k;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    D[1][2][1][1]=a[1];
    D[2][2][1][0]=a[2];
    D[3][2][2][2]=a[1]+a[2];
    for(i=3;i<n;++i){
        for(j=0;j<k&&j<i;++j){
            for(l=0;l<3;++l){
                D[1][i][j][l]=max(D[1][i-1][j][l],max(D[2][i-1][j][l],D[3][i-1][j][l]));
                if(!j||D[1][i-1][j][l])D[2][i][j+1][l]=D[1][i-1][j][l]+a[i];
                if(D[2][i-1][j][l])D[3][i][j+1][l]=D[2][i-1][j][l]+a[i];
            }
        }
    }
    for(l=0;l<2;++l)if(k<2||D[1][n-1][k-1][l])D[2][n][k][l]=D[1][n-1][k-1][l]+a[i];
    if(D[2][n-1][k-1][0])D[3][n][k][0]=D[2][n-1][k-1][0]+a[n];
    for(i=1;i<4;++i){
        for(j=1;j<=n;++j){
            for(l=0;l<3;++l)ans=max(ans,D[i][j][k][l]);
        }
    }
    printf("%d",ans);
    return 0;
}
