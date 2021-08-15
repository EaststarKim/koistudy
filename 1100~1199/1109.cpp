#include <stdio.h>
#include <algorithm>
int a[2010],D[2010][2010],p[2010][2010];
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",a+i);
        D[i][i]=a[i];
        p[i][i]=i;
        a[i]+=a[i-1];
    }
    for(i=1;i<n;++i){
        for(j=1;j<=n-i;++j){
            D[j][j+i]=1e9;
            for(k=p[j][j+i-1];k<=p[j+1][j+i];++k){
                int t=D[j][k-1]+D[k+1][j+i]+a[i+j]-a[j-1];
                if(t<D[j][j+i])D[j][j+i]=t,p[j][j+i]=k;
            }
        }
    }
    printf("%d",D[1][n]);
    return 0;
}
