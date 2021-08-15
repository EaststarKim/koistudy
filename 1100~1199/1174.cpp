#include <stdio.h>
#define M 1000000007
long long a[31],m=1;
int c[3010][1010]={{1}};
long long f(int n){
    int i;
    a[0]=n;
    for(i=0;1<<i<M-2;++i){
        if((1<<i)&M-2)m=(m*a[i])%M;
        a[i+1]=(a[i]*a[i])%M;
    }
    return m;
}
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    if(n<4||n%2){
        puts("-1");
        return 0;
    }
    n=n/2-1;
    for(i=0;i<=n*3;++i){
        for(j=0;j<=i&&j<=n;++j)c[i+1][j]=(c[i+1][j]+c[i][j])%M,c[i+1][j+1]=(c[i+1][j+1]+c[i][j])%M;
    }
    printf("%d",c[i][j]*f(n*2+1)%M);
    return 0;
}
