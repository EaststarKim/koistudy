#include <stdio.h>
int main()
{
	__int64 i,n,s=0;
	scanf("%I64d",&n);
	for(i=1;i<n;++i)s+=i*(n+1);
	printf("%I64d",s);
	return 0;
}