#include <stdio.h>
int D[510][510], d[510], p[510], t[510];
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d%d%d",d+i,p+i,t+i);
    D[1][1]=1;
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)if(i!=j || (i==n&&j==n)){
            if(t[j]&&i<j){
                for(k=j-1;k>0&&d[k]+p[j]>=d[j];--k)D[i][j]+=D[i][k];
            }
            else{
                for(k=i-1;k>0;--k){
                    if(d[k]+p[k]>=d[i])D[i][j]+=D[k][j];
                }
            }
            D[i][j]%=1000;
        }
    }
    printf("%d",D[n][n]);
    return 0;
}
