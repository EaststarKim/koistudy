#include <stdio.h>
#include <algorithm>
using namespace std;
int a[11],D[11][10010];
int main(){
    int i,j,k,n,m,t;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=0;i<=n;++i){
        for(j=0;j<=m;++j)D[i][j]=1e5;
    }
    D[0][0]=0;
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            for(k=1;k*k<=j;++k)D[i][j]=min(D[i][j],D[i-1][j-k*k]+(a[i]-k)*(a[i]-k));
        }
    }
    if(D[n][m]==1e5)D[n][m]=-1;
    printf("%d",D[n][m]);
    return 0;
}
