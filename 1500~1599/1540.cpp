#include <stdio.h>
long long D[10010],E[2510];
int main(){
    int i,j,k,m,n,x;
    scanf("%d%d%d",&m,&n,&x);
    D[0]=1;
    for(i=1;i<=n;++i){
        for(j=m*i;j>=0;--j){
            for(k=1;k<=m&&j>=k;++k)E[j]+=D[j-k];
        }
        for(j=0;j<=m*i;++j)D[j]=E[j],E[j]=0;
    }
    printf("%lld",D[x]);
    return 0;
}
