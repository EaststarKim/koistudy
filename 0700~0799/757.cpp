#include <stdio.h>
int a[60],cnt;
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<=n;++i)
	{
		for(j=i+1;j<=n;++j)
		{
			if(i!=j&&a[j]%a[i]==0)++cnt;
		}
	}
	printf("%d",cnt);
	return 0;
}