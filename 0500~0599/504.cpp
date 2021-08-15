#include <stdio.h>
#include <algorithm>
using namespace std;
int a[10010],D[2][5010][2],ans=1e9;
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<n;++i)scanf("%d",a+i);
    for(i=1;i<=n/2;++i)D[0][i][0]=D[0][i][1]=1e9;
    for(i=1;i<=n;++i){
        for(j=0;j<=n/2;++j)D[i%2][j][0]=D[i%2][j][1]=1e9;
        for(j=0;j<n/2;++j){
            D[i%2][j][0]=min(D[i%2][j][0],D[!(i%2)][j][0]+a[i]-a[i-1]);
            D[i%2][j+1][1]=min(D[i%2][j+1][1],D[!(i%2)][j][0]+a[i]);
            D[i%2][j][0]=min(D[i%2][j][0],D[!(i%2)][j][1]+a[i]);
            D[i%2][j+1][1]=min(D[i%2][j+1][1],D[!(i%2)][j][1]+a[i]-a[i-1]);
        }
        ans=min(ans,D[i%2][n/2][1]);
    }
    printf("%d",ans);
    return 0;
}
