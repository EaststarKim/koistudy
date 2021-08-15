#include <stdio.h>
#define M 100000007
int a[20][20];
int b[2][9]={{1,8,4,6,6,1,6,3,8},{2,0,8,0,8,7,5,7,8}};
int D[1<<20][9],E[1<<20][9];
int main(){
    int i,j,k,l,n;
    scanf("%d",&n);
    for(i=0;i<n;++i){
        for(j=0;j<n;++j)scanf("%d",a[i]+j);
    }
    D[0][0]=1;
    for(i=0;i<n;++i){
        for(j=1<<n;j--;)if(__builtin_popcount(j)==i){
            for(k=0;k<8;++k)if(D[j][k]){
                for(l=0;l<n;++l)if(!(j&(1<<l)))E[j|(1<<l)][b[a[i][l]][k]]=(E[j|(1<<l)][b[a[i][l]][k]]+D[j][k])%M;
            }
        }
        for(j=1<<n;j--;){
            for(k=0;k<8;++k)D[j][k]=E[j][k],E[j][k]=0;
        }
    }
    printf("%d",((D[(1<<n)-1][0]+D[(1<<n)-1][5])%M+D[(1<<n)-1][7])%M);
    return 0;
}
