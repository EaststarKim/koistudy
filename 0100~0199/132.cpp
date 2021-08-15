#include <stdio.h>
int main()
{
	int i, n, k, s=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&k),s+=k;
	printf("%d\n%.2f",s,(double)s/n);
	return 0;
}