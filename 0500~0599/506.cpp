#include <stdio.h>
int main()
{
	__int64 n,m;
	scanf("%I64d",&n);
	m=(n-1)/2*(n-1)+1;
	printf("%I64d %I64d",m,m+n*2-2);
	return 0;
}