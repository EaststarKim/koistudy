#include <stdio.h>
#define max(a,b) a>b? a:b
int m[510][510],a[510][510],mx;
int main()
{
	int i,j,k,n,b;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)scanf("%d",&m[i][j]);
	}
	for(i=1;i<=n;++i)
	{
		for(j=i;j<=n;++j)
		{
			a[i][j]=a[i][j-1]+m[1][j];
			mx=max(mx,a[i][j]);
		}
	}
	for(i=2;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			b=0;
			for(k=j;k<=n;++k)
			{
				b+=m[i][k];
				a[j][k]=max(a[j][k]+b,b);
				mx=max(mx,a[j][k]);
			}
		}
	}
	printf("%d",mx);
	return 0;
}
