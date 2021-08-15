#include <stdio.h>
int mx,cnt,w,h;
char a[1001][81];
void back(int r,int c)
{
	++cnt;
	a[r][c]='.';
	if(a[r+1][c]=='*')back(r+1,c);
	if(a[r-1][c]=='*')back(r-1,c);
	if(a[r][c+1]=='*')back(r,c+1);
	if(a[r][c-1]=='*')back(r,c-1);
}
int main()
{
	int i,j;
	scanf("%d%d",&w,&h);
	for(i=1;i<=h;++i)scanf("%s",a[i]+1);
	for(i=1;i<=h;++i)
	{
		for(j=1;j<=w;++j)
		{
			if(a[i][j]=='*')back(i,j);
			if(mx<cnt)mx=cnt;
			cnt=0;
		}
	}
	printf("%d",mx);
	return 0;
}