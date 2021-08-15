#include <stdio.h>
#define M 1000000007
int D[1010][1010][2][3];
int main(){
    int i,j,k,l,n,m;
    scanf("%d%d",&n,&m);
    D[1][1][0][0]=D[1][1][1][0]=1;
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            for(k=0;k<2;++k){
                for(l=0;l<2;++l)D[i+!k][j+k][k][l+1]=(D[i+!k][j+k][k][l+1]+D[i][j][k][l])%M;
                for(l=1;l<3;++l)D[i+k][j+!k][!k][1]=(D[i+k][j+!k][!k][1]+D[i][j][k][l])%M;
            }
        }
    }
    int ans=0;
    for(i=0;i<2;++i){
        for(j=1;j<3;++j)ans=(ans+D[n][m][i][j])%M;
    }
    printf("%d",ans);
    return 0;
}
