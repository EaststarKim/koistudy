#include <stdio.h>
#include <string.h>
int a[510][510],chk[510],cnt[510],k,s;
void back(int p)
{
	int i;
	if(a[p][0]==0)return;
	for(i=1;i<=a[p][0];++i)
	{
		if(chk[a[p][i]]==0)
		{
			chk[a[p][i]]=1;
			++cnt[k];
			++cnt[a[p][i]];
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
		if(cnt[i]==n-1)++s;
	}
	printf("%d",s);
	return 0;
}