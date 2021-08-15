#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100010],A[100010][110],B[100010][110],D[100010][110],ans=1e9;
int main(){
    int i,j,n,c;
    scanf("%d%d",&n,&c);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i<=n;++i){
    	A[i][a[i-1]-1]=A[i][a[i]]=1e9;
        for(j=a[i-1];j<=a[i];++j)A[i][j]=min(A[i][j-1],D[i-1][j]-j*c);
        B[i][101]=1e9;
        for(j=100;j>=a[i];--j)B[i][j]=min(B[i][j+1],D[i-1][j]+j*c);
        for(j=1;j<a[i];++j)D[i][j]=1e9;
        D[i][j]=min(A[i][j]+j*c,B[i][j]-j*c);
        for(++j;j<101;++j)D[i][j]=B[i][j]-j*c+(j-a[i])*(j-a[i]);
    }
    for(i=a[n];i<101;++i)ans=min(ans,D[n][i]);
    printf("%d",ans);
    return 0;
}
