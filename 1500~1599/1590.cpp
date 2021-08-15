#include <stdio.h>
#define M 1000000007
int a[11][11][9];
long long D[11][11];
int main(){
    int i,j,k,l,n,h,r;
    scanf("%d%d%d",&n,&h,&r);
    for(i=1;i<=n;++i){
        scanf("%d",a[i][0]);
        for(j=1;j<=a[i][0][0];++j){
            scanf("%d",a[i][j]);
            for(k=1;k<=a[i][j][0];++k)scanf("%d",a[i][j]+k);
        }
    }
    for(i=1;i<=n;++i)D[1][i]=1;
    for(i=2;i<=h;++i){
        for(j=1;j<=n;++j){
            for(k=1;k<=a[j][0][0];++k){
                long long t=1;
                for(l=1;l<=a[j][k][0];++l)t=t*D[i-1][a[j][k][l]]%M;
                D[i][j]=(D[i][j]+t)%M;
            }
        }
    }
    printf("%d",D[h][r]);
    return 0;
}
