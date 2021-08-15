#include <stdio.h>
int a[301][301];
__int64 b[301][301];
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)scanf("%d",&a[i][j]);
	}
	if(a[1][1])b[1][1]=1;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			if(a[i][j])b[i][j]+=(b[i-1][j]+b[i][j-1])%1000000007;
		}
	}
	if(b[n][n])printf("%I64d",b[n][n]);
	else printf("-1");
	return 0;
}