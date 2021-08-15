#include <stdio.h>
#define M 1000000007
int a[1010][1010],D[1010][1010][7];
int main(){
    int i,j,k,l,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)scanf("%d",a[i]+j);
    }
    D[1][1][a[1][1]%7]=1;
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j){
            for(k=0;k<7;++k){
                l=(k*10+a[i+1][j])%7;
                D[i+1][j][l]=(D[i+1][j][l]+D[i][j][k])%M;
                l=(k*10+a[i][j+1])%7;
                D[i][j+1][l]=(D[i][j+1][l]+D[i][j][k])%M;
            }
        }
    }
    printf("%d",D[n][n][0]);
    return 0;
}
