#include <stdio.h>

int a[100010];

int main()
{
	int i, j;
	int n, k, b, t;
	scanf("%d",&n);
	for(i=1;i<=n;++i) scanf("%d",&a[i]);
	b=n;
	while(b/=2)
	{
		for(i=1;i<=b;++i)
		{
			for(j=i+b;j<=n;j+=b)
			{
				t=a[j];
				k=j;
				while(k>b && a[k-b]>t) a[k]=a[k-b], k-=b;
				a[k]=t;
			}
		}
	}
	for(i=1;i<=n;++i) printf("%d ",a[i]);
	return 0;
}