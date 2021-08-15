#include <stdio.h>

int main()
{
	int i, n;
	scanf("%d",&n);
	n=n*2-1;
	for(i=1;i<=n;++i) printf("*");
	printf("\n");
	return 0;
}