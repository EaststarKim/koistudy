#include <stdio.h>
#include <algorithm>
using namespace std;
int a[31][31],cnt[900],dr[]={1,-1,0,0},dc[]={0,0,-1,1},p;
void back(int r,int c)
{
	int i;
	a[r][c]=0;
	for(i=0;i<4;++i)
	{
		if(a[r+dr[i]][c+dc[i]])
		{
			++cnt[p];
			back(r+dr[i],c+dc[i]);
		}
	}
}
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)scanf("%1d",&a[i][j]);
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			if(a[i][j])
			{
				++cnt[++p];
				back(i,j);
			}
		}
	}
	sort(&cnt[1],&cnt[p+1]);
	printf("%d\n",p);
	for(i=1;i<=p;++i)printf("%d\n",cnt[i]);
	return 0;
}