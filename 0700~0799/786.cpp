#include <stdio.h>
#define M 1000000007
int D[1010][1010][31]={{{1}}},s;
int main()
{
    int i,j,k,n,m,a,b,l;
    scanf("%d%d%d%d%d",&n,&m,&a,&b,&l);
    for(i=1;i<=n;++i){
        for(j=0;j<i&&j<=m;++j){
            for(k=0;k<=l;++k)if(D[i-1][j][k]){
                if(k+a>l)D[i][j+1][0]=(D[i][j+1][0]+D[i-1][j][k])%M;
                else D[i][j][k+a]=(D[i][j][k+a]+D[i-1][j][k])%M;
                if(k-b<0)D[i][j][0]=(D[i][j][0]+D[i-1][j][k])%M;
                else D[i][j][k-b]=(D[i][j][k-b]+D[i-1][j][k])%M;
            }
        }
    }
    for(i=0;i<=l;++i)s=(s+D[n][m][i])%M;
    if(!s)s=-1;
    printf("%d",s);
    return 0;
}
