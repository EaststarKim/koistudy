#include <stdio.h>

int main()
{
	__int64 n;
	scanf("%I64d",&n);
	if(n%2) printf("odd\n");
	else printf("even\n");
	return 0;
}