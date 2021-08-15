#include <stdio.h>
const long long M=1e18;
int main(){
	long long a,b,c=0;
	scanf("%lld%lld",&a,&b);
	while(a){
		if(a%2)c+=b;
		a>>=1;
		b<<=1;
		b%=M,c%=M;
	}
	printf("%lld",c);
	return 0;
}
