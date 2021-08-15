#include <stdio.h>
int a[60][60],b[60][60],dr[]={-1,0,1,0},dc[]={0,1,0,-1},m;
void back(int r,int c)
{
	int i,nr,nc;
	for(i=0;i<4;++i)
	{
		nr=r+dr[i];
		nc=c+dc[i];
		if(nr<1||nr>m||nc<1||nc>m||a[nr][nc]==1||b[nr][nc]<=b[r][c]+1)continue;
		b[nr][nc]=b[r][c]+1;
		back(nr,nc);
	}
}
int main()
{
	int i,j,n;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		for(j=1;j<=m;++j)
		{
			scanf("%d",&a[i][j]);
			b[i][j]=2510;
		}
	}
	b[1][1]=0;
	if(!a[1][1])back(1,1);
	if(b[m][m]==2510)printf("No way");
	else if(b[m][m]>n)printf("Not enough time");
	else printf("Possible");
	return 0;
}