#include <stdio.h>
int a[51][51],b[51][51],q[2][2510],dr[]={-1,0,1,0},dc[]={0,1,0,-1},n;
void BFS()
{
	int i,ro,co,nr,nc,f=0,r=1;
	while(f<r)
	{
		ro=q[0][++f];
		co=q[1][f];
		for(i=0;i<4;++i)
		{
			nr=ro+dr[i];
			nc=co+dc[i];
			if(nr<1||nr>n||nc<1||nc>n||b[nr][nc]<=b[ro][co]+(!a[nr][nc]))continue;
			b[nr][nc]=b[ro][co]+(!a[nr][nc]);
			q[0][++r]=nr;
			q[1][r]=nc;
		}
	}
}
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			scanf("%1d",&a[i][j]);
			b[i][j]=2501;
		}
	}
	b[1][1]=0;
	q[0][1]=q[1][1]=1;
	BFS();
	printf("%d",b[n][n]);
	return 0;
}
