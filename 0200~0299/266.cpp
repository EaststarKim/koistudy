#include <stdio.h>
int a[1010][1010],mx;
int main()
{
	int i,j,r;
	scanf("%d",&r);
	for(i=1;i<=r;++i)
	{
		for(j=1;j<=i;++j)scanf("%d",&a[i][j]);
	}
	for(i=2;i<=r;++i)
	{
		for(j=1;j<=i;++j)
		{
			a[i][j]+=(a[i-1][j-1]>a[i-1][j]? a[i-1][j-1]:a[i-1][j]);
		}
	}
	for(i=1;i<=r;++i)
	{
		if(mx<a[r][i])mx=a[r][i];
	}
	printf("%d",mx);
	return 0;
}