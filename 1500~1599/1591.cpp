#include <stdio.h>
#define M 1000000007
int a[110],s[110],D[110][110],cnt;
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%1d",a+i);
        if(a[i])++cnt;
        else ++s[cnt];
    }
    if(cnt<2){
        printf("%d",cnt);
        return 0;
    }
    --cnt;
    for(i=0;i<=n;++i)D[cnt][i]=1;
    for(i=cnt;i--;){
        for(j=0;j<=n;++j){
            for(k=1;k<=s[i]+j;++k)D[i][j]=(D[i][j]+D[i+1][k])%M;
        }
    }
    printf("%d",D[0][0]);
    return 0;
}
