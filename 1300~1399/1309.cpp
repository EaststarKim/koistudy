#include <stdio.h>
#define M 1000000007
int a[100010][5];
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<=n;++i){
        a[i][0]=1;
        for(j=1;j<=i&&j<5;++j)a[i][j]=(a[i-1][j]+a[i-1][j-1])%M;
    }
    printf("%d",(a[n][4]+a[n][2]+1)%M);
    return 0;
}
