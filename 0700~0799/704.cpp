#include <stdio.h>
int a[11][11],cnt,n;
void back(int r,int c)
{
	if(r==n&&c==n)
	{
		++cnt;
		return;
	}
	if(r<n&&a[r+1][c])back(r+1,c);
	if(c<n&&a[r][c+1])back(r,c+1);
}
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)scanf("%d",&a[i][j]);
	}
	back(1,1);
	if(cnt)printf("%d",cnt);
	else printf("-1");
	return 0;
}