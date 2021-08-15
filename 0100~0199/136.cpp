#include <stdio.h>

int main()
{
	int i, n, k, m;
	scanf("%d %d",&n, &k);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&m);
		if(m==k) break;
	}
	if(i>n) printf("-1");
	else printf("%d\n",i);
	return 0;
}