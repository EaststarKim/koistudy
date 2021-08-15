#include <stdio.h>
int chk[101][101],cnt;
char a[101][101],b;
void back(int r,int c)
{
	chk[r][c]=1;
	if(a[r+1][c]=='L'&&chk[r+1][c]==0)back(r+1,c);
	if(a[r-1][c]=='L'&&chk[r-1][c]==0)back(r-1,c);
	if(a[r][c+1]=='L'&&chk[r][c+1]==0)back(r,c+1);
	if(a[r][c-1]=='L'&&chk[r][c-1]==0)back(r,c-1);
	if(a[r+1][c+1]=='L'&&chk[r+1][c+1]==0)back(r+1,c+1);
	if(a[r+1][c-1]=='L'&&chk[r+1][c-1]==0)back(r+1,c-1);
	if(a[r-1][c+1]=='L'&&chk[r-1][c+1]==0)back(r-1,c+1);
	if(a[r-1][c-1]=='L'&&chk[r-1][c-1]==0)back(r-1,c-1);
}
int main()
{
	int i,j,w,h;
	scanf("%d%d",&w,&h);
	for(i=1;i<=h;++i)
	{
		for(j=1;j<=w;++j)scanf("%s%c",&a[i][j],&b);
	}
	for(i=1;i<=h;++i)
	{
		for(j=1;j<=w;++j)
		{
			if(a[i][j]=='L'&&chk[i][j]==0)
			{
				++cnt;
				back(i,j);
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
