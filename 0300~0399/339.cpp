#include <stdio.h>
#include <string.h>
int a[100][100],chk[100],cnt[3][100],k,s;
void back(int p)
{
	int i;
	if(a[p][0]==0)return;
	for(i=1;i<=a[p][0];++i)
	{
		if(chk[a[p][i]]==0)
		{
			chk[a[p][i]]=1;
			++cnt[1][k];
			++cnt[2][a[p][i]];
			back(a[p][i]);
		}
	}
}
int main()
{
	int i,x,y,n,m;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		a[x][++a[x][0]]=y;
	}
	for(i=1;i<=n;++i)
	{
		k=i;
		if(a[i][0])back(i);
		memset(chk,0,sizeof(chk));
	}
	for(i=1;i<=n;++i)
	{
		if((cnt[1][i]>=(n+1)/2)||(cnt[2][i]>=n-(n+1)/2+1))++s;
	}
	printf("%d",s);
	return 0;
}