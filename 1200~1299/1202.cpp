#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1010],b[1010],D[1010][1010],ans=2e9;
int main(){
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i<=m;++i)scanf("%d",b+i);
    for(i=0;i<=n;++i)for(j=0;j<=m;++j)D[i][j]=2e9;
    D[0][0]=0;
    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            D[i][j+1]=min(D[i][j+1],D[i][j]);
            D[i+1][j+1]=min(D[i+1][j+1],D[i][j]+a[i+1]*b[j+1]);
        }
    }
    for(;i<=m;++i)ans=min(ans,D[n][i]);
    printf("%d",ans);
    return 0;
}
