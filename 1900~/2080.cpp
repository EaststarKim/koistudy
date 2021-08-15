#include <stdio.h>
int q[100010];
long long a[100010],D[210][100010];
int main(){
    int i,j,n,k,f,r;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;++i)scanf("%lld",a+i),a[i]+=a[i-1],D[0][i]=-a[i]*a[i];
    for(i=1;i<=k;++i){
        q[f=r=1]=i;
        for(j=i+1;j<=n;++j){
            while(f<r&&a[q[f]]*a[j]+D[i-1][q[f]]<=a[q[f+1]]*a[j]+D[i-1][q[f+1]])++f;
            D[i][j]=a[q[f]]*a[j]+D[i-1][q[f]]-a[j]*a[j];
            while(f<r&&(D[i-1][q[r]]-D[i-1][q[r-1]])*(a[q[r-1]]-a[j])>=(D[i-1][j]-D[i-1][q[r-1]])*(a[q[r-1]]-a[q[r]]))--r;
            q[++r]=j;
        }
    }
    printf("%lld",D[k][n]+a[n]*a[n]);
    return 0;
}
