#include <stdio.h>
#define M 1000000007
int D[8010][8010];
int main(){
    int i,j,n;
    scanf("%d",&n);
    D[1][1]=D[2][2]=1;
    for(i=1;i<=n;++i){
        for(j=i;--j;)D[i][j]=(D[i][j]+D[i][j+1])%M;
        for(j=1;j<=i&&i+j+1<n;++j)D[i+j+2][j+2]=(D[i+j+2][j+2]+D[i][j])%M;
        D[i+1][1]=(D[i+1][1]+D[i][1])%M;
        D[i+2][2]=(D[i+2][2]+D[i][1])%M;
    }
    printf("%d",D[n][1]);
    return 0;
}
