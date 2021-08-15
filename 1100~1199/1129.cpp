#include <stdio.h>
int a[110],D[110][760]={{1}};
void f(int i,int j,int k,int s){
    if(s>700)return;
    if(j+s<701)D[i][j+s]=(D[i][j+s]+D[k][j])%1000000007;
    if(j>=s)D[i][j-s]=(D[i][j-s]+D[k][j])%1000000007;
}
int main(){
    int i,j,n,k;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i<=n;++i){
        for(j=0;j<=700;++j)if(D[i-1][j])f(i,j,i-1,a[i]);
        if(i>1)for(j=0;j<=700;++j)if(D[i-2][j])f(i,j,i-2,a[i-1]*10+a[i]);
        if(i>2)for(j=0;j<=700;++j)if(D[i-3][j])f(i,j,i-3,a[i-2]*100+a[i-1]*10+a[i]);
    }
    printf("%d\n",D[n][k]);
	return 0;
}
