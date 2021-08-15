#include <stdio.h>
int main()
{
	int i, n;
	scanf("%d",&n);
	for(i=1;i*i<=n;++i);
	printf("%d\n",i-1);
	return 0;
}