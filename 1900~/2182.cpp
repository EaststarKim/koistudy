#include <stdio.h>
const int M=1e9+7;
long long t[100010],a[100010],b[100010],c[100010],d[100010],A,B,C,D;
int sq(long long x){return x*x;}
int cb(long long x){return x*x*x;}
int main(){
	int i,n,m,s,e;
	scanf("%d%d",&n,&m);
	for(;m--;){
		scanf("%d%d",&s,&e);
		s=1,e=n;
		++t[s],++e;
		s=e-s+1;
		++a[e],b[e]=(b[e]+s)%M,c[e]=(c[e]+sq(s))%M,d[e]=(d[e]+cb(s))%M;
	}
	for(i=1;i<=n;++i){
		A+=t[i],B+=t[i],C+=t[i],D+=t[i];
		A-=a[i],B=(B-b[i])%M,C=(C-c[i])%M,D=(D-d[i])%M;
		printf("%d ",(D+M)%M);
		D=(D+3*C+3*B+A)%M,C=(C+2*B+A)%M,B=(B+A)%M;
	}
	return 0;
}
