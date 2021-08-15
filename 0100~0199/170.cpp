#include <stdio.h>
#include <stdlib.h>
int a[2010][2010],chk[2010],n,cnt;
void back(int p)
{
	int i;
	printf("%d ",p);
	++cnt;
	if(cnt==n)exit(0);
	for(i=1;i<=a[p][0];++i)
	{
		if(chk[a[p][i]]==0)
		{
			chk[a[p][i]]=1;
			back(a[p][i]);
		}
	}
}
int main()
{
	int i, m, x, y;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d %d",&x,&y);
		++a[x][0];
		++a[y][0];
		a[x][a[x][0]]=y;
		a[y][a[y][0]]=x;
	}
	chk[1]=1;
	back(1);
	return 0;
}