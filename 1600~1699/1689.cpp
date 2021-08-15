#include <stdio.h>
int c[20][20],D[4096][20057];
int main(){
    int i,j,k,l,n,s,t;
    scanf("%d%d",&n,&s);
    for(i=0;i<n;++i){
        c[i][0]=1;
        for(j=1;j<=i;++j)c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
    D[0][0]=1;
    t=(1<<n)-1;
    for(i=0;i<n;++i){
        for(j=0;j<t;++j)if(__builtin_popcount(j)==i){
            for(k=0;k<20057;++k)if(D[j][k]){
                for(l=0;l<n;++l)if(!(j&(1<<l))&&c[n-1][l]*(i+1)<20057)D[j+(1<<l)][k+c[n-1][l]*(i+1)]+=D[j][k];
            }
        }
    }
    printf("%d",D[t][s]);
    return 0;
}
