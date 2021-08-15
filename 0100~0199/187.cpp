#include <stdio.h>
int main()
{
	int i,n;
	__int64 s=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)if(n%i==0)s+=i;
	printf("%I64d",s);
	return 0;
}