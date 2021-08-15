#include <stdio.h>
#define M 1000000007
long long D[110][110],ans;
int main(){
    int i,j,n;
    scanf("%d",&n);
    D[0][1]=1;
    D[1][2]=1;
    for(i=2;i<=n;++i){
        for(j=2;j<=i+1;++j){
            long long t=D[i-1][j-1]+D[i-2][j-1]*D[i-2][j-1]%M;
            D[i][j]=(D[i][j]+t*t)%M;
        }
    }
    for(i=1;i<=n+1;++i)ans=(ans+D[n][i])%M;
    printf("%lld",ans);
    return 0;
}
