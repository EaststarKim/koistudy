#include <stdio.h>
int a[101];
int main()
{
	int i,j,n,m;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<=n;++i)
	{
		m=1;
		for(j=1;j<=n;++j)
		{
			if(a[i]<a[j])++m;
		}
		printf("%d %d\n",a[i],m);
	}
	return 0;
}