#include <stdio.h>
int a[110][110],cnt[110];
int main()
{
	int i,j,k,l,x,y,n,m,p;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		a[x][y]=a[y][x]=1;
	}
	for(k=1;k<=n;++k)
	{
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
			{
				if(a[i][k] && a[k][j])a[i][j]=a[j][i]=1;
			}
		}
	}
	for(i=1;i<=n;++i)
	{
		a[i][i]=1;
		for(j=1;j<=n;++j)
		{
			if(a[i][j])++cnt[i];
		}
	}
	p=n-m-1;
	printf("%d\n",p);
	for(l=1;l<=p;++l)
	{
		for(j=1;j<=n;++j)
		{
			for(k=1;k<=n;++k)
			{
				if(a[j][k]==0)
				{
					printf("%d %d\n",j,k);
					a[j][k]=a[k][j]=1;
					break;
				}
			}
			if(k<=n)break;
		}
		for(k=1;k<=n;++k)
		{
			for(i=1;i<=n;++i)
			{
				for(j=1;j<=n;++j)
				{
					if(a[i][k] && a[k][j])a[i][j]=a[j][i]=1;
				}
			}
		}
	}
	return 0;
}