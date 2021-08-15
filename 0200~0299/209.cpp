#include <stdio.h>
int a[360][360],mx;
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=i;++j)scanf("%d",&a[i][j]);
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=i;++j)
		{
			if(a[i-1][j-1]>a[i-1][j])a[i][j]+=a[i-1][j-1];
			else a[i][j]+=a[i-1][j];
		}
	}
	for(i=1;i<=n;++i)
	{
		if(mx<a[n][i])mx=a[n][i];
	}
	printf("%d",mx);
	return 0;
}