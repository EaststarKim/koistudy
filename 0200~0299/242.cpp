#include <stdio.h>
int D[50][3010]={{1}};
int main()
{
    int i,j,k,n,m,s;
    scanf("%d%d%d",&n,&m,&s);
    n*=n;
    for(i=1;i<=m;++i){
        for(j=n-1;j>=0;--j){
            for(k=s-i;k>=0;--k){
                if(D[j][k])D[j+1][k+i]=(D[j+1][k+i]+D[j][k])%100000;
            }
        }
    }
    printf("%d",D[n][s]);
    return 0;
}
