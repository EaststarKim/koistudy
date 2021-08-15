#include <stdio.h>
int a[71],n,m,sw;
void back(int p,int s)
{
	int i;
	if(p>4)
	{
		if(s==m)sw=1;
		return;
	}
	for(i=1;i<=n;++i)
	{
		if(s+a[i]<=m)back(p+1,s+a[i]);
	}
}
int main()
{
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	back(1,0);
	if(sw)printf("YES");
	else printf("NO");
	return 0;
}