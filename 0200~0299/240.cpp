#include <stdio.h>
int a[91][91],n,m,mx;
void back(int r,int c,int s)
{
	if(r>1&&a[r-1][c])
	{
		a[r][c]=0;
		back(r-1,c,s+1);
		a[r][c]=1;
	}
	if(r<n&&a[r+1][c])
	{
		a[r][c]=0;
		back(r+1,c,s+1);
		a[r][c]=1;
	}
	if(c>1&&a[r][c-1])
	{
		a[r][c]=0;
		back(r,c-1,s+1);
		a[r][c]=1;
	}
	if(c<m&&a[r][c+1])
	{
		a[r][c]=0;
		back(r,c+1,s+1);
		a[r][c]=1;
	}
	if(mx<s)mx=s;
	return;
}
int main()
{
	int i,j;
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)scanf("%d",&a[i][j]);
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
		{
			if(a[i][j])back(i,j,1);
		}
	}
	printf("%d",mx);
	return 0;
}