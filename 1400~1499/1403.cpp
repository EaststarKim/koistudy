#include <stdio.h>
#define M 1000000007
int a[1010][1010];
int main(){
	int i,j,n,m;
	scanf("%d%d",&m,&n);
	n=m-n;
	if(!n){
        if(m<3)puts("1");
        else puts("0");
        return 0;
	}
	a[1][1]=a[2][1]=a[3][1]=1;
	for(i=2;i<=n;++i){
        for(j=i;j<=m;++j){
            if(j>3)a[j][i]+=a[j-3][i-1];
            if(j>2)a[j][i]+=a[j-2][i-1];
            a[j][i]=(a[j][i]%M+a[j-1][i-1])%M;
        }
	}
	printf("%d",(a[m][n]+a[m-1][n]+a[m-2][n])%M);
	return 0;
}
