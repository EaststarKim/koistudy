#include <stdio.h>
#define M 100000007
int D[1010][20][20],ans;
int x[]={-1,-1,0,1,1,1,0,-1},y[]={0,1,1,1,0,-1,-1,-1};
int main(){
    int i,j,k,n,m,l,nr,nc;
    scanf("%d%d%d",&n,&m,&l);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)D[l][i][j]=1;
    }
    for(;l;--l){
        for(i=1;i<=n;++i){
            for(j=1;j<=m;++j){
                for(k=0;k<8;++k){
                    nr=i+x[k],nc=j+y[k];
                    D[l-1][nr][nc]=(D[l-1][nr][nc]+D[l][i][j])%M;
                }
            }
        }
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)ans=(ans+D[0][i][j])%M;
    }
    printf("%d",ans);
    return 0;
}
