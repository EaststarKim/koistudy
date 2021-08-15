#include <stdio.h>
int a[2010];
int main()
{
	int i,j,n,p;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<=n;++i)
	{
		p=1;
		for(j=1;j<=n;++j)
		{
			if(a[i]<a[j])++p;
		}
		printf("%d\n",p);
	}
	return 0;
}