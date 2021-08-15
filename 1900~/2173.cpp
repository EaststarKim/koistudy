#include <stdio.h>
const int M=1e9+7;
int a[100010],b[100010],c[100010];
long long A,B,C;
int main(){
	int i,n,q,s,e;
	scanf("%d%d",&n,&q);
	for(;q--;){
		scanf("%d%d",&s,&e);
		++a[s],--a[++e];
		b[e]=(b[e]+e-s)%M;
		c[e]=(c[e]+(long long)(e-s)*(e-s+1)/2%M)%M;
	}
	for(i=1;i<=n;++i){
		A+=a[i],B=(B-b[i]+A)%M,C=(C-c[i]+B)%M;
		printf("%d ",(C+M)%M);
	}
	return 0;
}
