#include <stdio.h>
int a[20][20],chk[20],n,x,y,cnt;
void back(int p)
{
	int i;
	if(p==y)
	{
		++cnt;
		return;
	}
	for(i=1;i<=n;++i)
	{
		if(a[p][i]&&chk[i]==0)
		{
			chk[i]=1;
			back(i);
			chk[i]=0;
		}
	}
}
int main()
{
	int i,k;
	scanf("%d%d",&n,&k);
	for(i=1;i<=k;++i)scanf("%d%d",&x,&y),a[x][y]=a[y][x]=1;
	scanf("%d%d",&x,&y);
	chk[x]=1;
	back(x);
	printf("%d",cnt);
	return 0;
}