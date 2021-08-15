#include <stdio.h>
int h[220][220],s[220][220],D[220][220];
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)for(j=1;j<=n;++j)scanf("%d",h[i]+j);
    for(i=1;i<=n;++i)for(j=1;j<=n;++j)scanf("%d",s[i]+j);
    h[0][1]=1e9,D[0][1]=1;
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j){
            if(D[i-1][j]&&h[i-1][j]>=h[i][j])D[i][j]=D[i-1][j]+s[i][j];
            if(D[i][j-1]&&h[i][j-1]>=h[i][j]&&(!D[i][j]||D[i][j]>D[i][j-1]+s[i][j]))D[i][j]=D[i][j-1]+s[i][j];
        }
    }
    printf("%d",D[n][n]-1);
    return 0;
}
