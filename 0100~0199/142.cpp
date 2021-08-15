#include <stdio.h>

int main()
{
	int i;
	int n, m, k;
	scanf("%d %d",&n, &m);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&k);
		if(k==m)
		{
			printf("%d",i);
			break;
		}
	}
	if(i>n) printf("-1");
	return 0;
}