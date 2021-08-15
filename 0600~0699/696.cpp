#include <stdio.h>
int a[20001];
int main()
{
	int i,j,n,x;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&x);
		if(a[x])
		{
			for(j=i;j>x;--j)a[j]=a[j-1];
		}
		a[x]=i;
	}
	for(i=1;i<=n;++i)printf("%d\n",a[i]);
	return 0;
}