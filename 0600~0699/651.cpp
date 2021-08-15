#include<stdio.h>
long long a[40][40],k=3;
int main(){
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    if(n%3){
        puts("0");
        return 0;
    }
    n/=3,a[1][0]=1;
    for(i=2;i<=n;++i,k*=3)a[i][0]=a[i-1][0]*2;
    for(i=1;i<=m;++i){
        for(j=i+1;j<=n;j++)a[j][i]=a[j-1][i]*2+a[j-1][i-1];
    }
    if(a[n][m]){
        while(a[n][m]%3==0)a[n][m]/=3,k/=3;
        printf("%lld/%lld",a[n][m],k);
    }
    else puts("0");
    return 0;
}
