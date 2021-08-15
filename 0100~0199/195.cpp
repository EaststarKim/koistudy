#include <stdio.h>
int main()
{
	int i,j,n,m;
	scanf("%d",&n);
	m=n*(n-1)/2;
	printf("%d\n",m);
	for(i=1;i<=n;++i)
	{
		for(j=n;j>i;--j)printf("%d %d\n",i,j);
	}
	return 0;
}