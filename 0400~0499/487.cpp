#include <stdio.h>
int a[201][201],cnt;
int main()
{
	int i,j,k,n,m,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		a[x][y]=a[y][x]=1;
	}
	for(i=1;i<n-1;++i)
	{
		for(j=i+1;j<n;++j)
		{
			if(!a[i][j])
			{
				for(k=j+1;k<=n;++k)
				{
					if(!a[i][k]&&!a[j][k])++cnt;
				}
			}
		}
	}
	printf("%d",cnt);
	return 0;
}