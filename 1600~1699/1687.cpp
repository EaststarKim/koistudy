#include <stdio.h>
int a[110][110];
long long D[110][110];
int main(){
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)scanf("%d",a[i]+j);
    }
    D[0][1]=1;
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)if(a[i][j])D[i][j]+=D[i-1][j]+D[i][j-1];
    }
    printf("%lld",D[n][m]);
    return 0;
}
