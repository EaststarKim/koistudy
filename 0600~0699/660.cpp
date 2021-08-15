#include <stdio.h>
int a[1501][1501],b[1501],mx,mj;
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)scanf("%d",&a[i][j]);
		b[i]=n;
	}
	for(i=1;i<=n;++i)
	{
		mx=0;
		for(j=1;j<=n;++j)
		{
			if(mx<a[b[j]][j])
			{
				mx=a[b[j]][j];
				mj=j;
			}
		}
		--b[mj];
	}
	printf("%d",mx);
	return 0;
}