#include <stdio.h>

int main()
{
	int i, n, m, k;
	scanf("%d",&n);
	m=n;
	k=1;
	while(m/10)
	{
		++k;
		m/=10;
	}
	for(i=1;i<=k;++i)
	{
		printf("%d",n%10);
		n/=10;
	}
	printf("\n");
	return 0;
}