#include <stdio.h>
int D[20][20];
int main(){
    int i,j,n,m,k,r,c;
    scanf("%d%d%d",&n,&m,&k);
    r=(k+m-1)/m;
    c=k%m?k%m:m;
    if(!k)r=c=1;
    D[0][1]=1;
    for(i=1;i<=r;++i)for(j=1;j<=c;++j)D[i][j]=D[i-1][j]+D[i][j-1];
    for(i=r;i<=n;++i)for(j=c;j<=m;++j)D[i][j]=D[i-1][j]+D[i][j-1];
    printf("%d",D[n][m]);
    return 0;
}
