#include <stdio.h>
long long D[251][251];
int main(){
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    D[0][m]=1;
    for(i=1;i<=m;++i){
        for(k=0;k<=n;++k){
            for(j=0;j<=n-(m-i+1)*k;++j)D[i][j+(m-i+1)*k]+=D[i-1][j];
        }
    }
    printf("%d",D[m][n]);
    return 0;
}
