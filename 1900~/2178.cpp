#include <stdio.h>
int D[250][250]={{1}};
int main(){
	int i,j,k,n,m;
	scanf("%d%d",&n,&m);
	n-=m;
	for(i=0;i<m;++i){
		for(j=0;j<=n;++j)if(D[i][j]){
			for(k=0;(m-i)*k+j<=n;++k)D[i+1][(m-i)*k+j]+=D[i][j];
		}
	}
	printf("%d",D[m][n]);
	return 0;
}
