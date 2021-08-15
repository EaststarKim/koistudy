#include <stdio.h>
int a[501][501],b[501],cnt;
int main()
{
	int i,j,n,m,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		a[x][y]=a[y][x]=1;
	}
	for(i=1;i<=n;++i)
	{
		if(a[1][i])
		{
			b[i]=1;
			for(j=2;j<=n;++j)
			{
				if(a[i][j])b[j]=1;
			}
		}
	}
	for(i=1;i<=n;++i)
	{
		if(b[i])++cnt;
	}
	printf("%d",cnt);
	return 0;
}