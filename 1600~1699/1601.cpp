#include <stdio.h>
#define M 1000000007
long long f[110]={1},c[110][110],D[110][110],ans;
int main(){
    int i,j,k,n,l,r;
    scanf("%d%d%d",&n,&l,&r);
    for(i=1;i<=n;++i)f[i]=f[i-1]*i%M;
    for(i=0;i<=n;++i){
        c[i][0]=1;
        for(j=1;j<=i;++j)c[i][j]=(c[i-1][j]+c[i-1][j-1])%M;
    }
    D[0][0]=1;
    for(i=1;i<=n;++i){
        for(j=1;j<=i;++j){
            for(k=j;k<=i;++k)D[i][j]=(D[i][j]+c[i-1][k-1]*D[k-1][j-1]%M*f[i-k])%M;
        }
    }
    for(i=l;i<=n-r+1;++i)ans=(ans+c[n-1][i-1]*D[i-1][l-1]%M*D[n-i][r-1])%M;
    printf("%d",ans);
    return 0;
}
