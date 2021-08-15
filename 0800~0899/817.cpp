#include <stdio.h>
#define M 100000007
int a[110][110],e[110],D[1010][110],ans;
int main(){
    int i,j,n,m,k,l,x;
    scanf("%d%d%d%d%d",&n,&m,&k,&l,&x);
    for(;m--;)scanf("%d",&i),D[1][i]=1;
    for(;x--;)scanf("%d%d",&i,&j),a[i][j]=1;
    for(;k--;)scanf("%d",&i),e[i]=1;
    for(i=1;i<l;++i){
        for(j=0;j<n;++j)if(D[i][j]){
            for(k=0;k<n;++k)if(a[j][k])D[i+1][k]=(D[i+1][k]+D[i][j])%M;
        }
    }
    for(i=0;i<n;++i)if(e[i])ans=(ans+D[l][i])%M;
    printf("%d\nStaLanTia",ans);
    return 0;
}
