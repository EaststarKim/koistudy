#include <stdio.h>

int a[5000];

int main()
{
	int i, j, n, t;
	scanf("%d",&n);
	for(i=1;i<=n;++i) scanf("%d",&a[i]);
	for(i=1;i<=n;++i)
	{
		for(j=i;j<=n;++j)
		{
			if(a[i]>a[j])
			{
				t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
		}
	}
	for(i=1;i<=n;++i) printf("%d ",a[i]);
	return 0;
}