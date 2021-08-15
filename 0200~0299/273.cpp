#include <stdio.h>
int a[16][26],b[16],c[26],d[26],e[16],cnt,mn=16,v,g;
void back(int p)
{
	int i;
	if(p>g)
	{
		for(i=1;i<=v;++i)
		{
			if(c[i]<d[i])break;
		}
		if(i>v&&mn>cnt)
		{
			mn=cnt;
			for(i=1;i<=mn;++i)e[i]=b[i];
		}
		return;
	}
	b[++cnt]=p;
	for(i=1;i<=v;++i)c[i]+=a[p][i];
	back(p+1);
	--cnt;
	for(i=1;i<=v;++i)c[i]-=a[p][i];
	back(p+1);
}
int main()
{
	int i,j;
	scanf("%d",&v);
	for(i=1;i<=v;++i)scanf("%d",&d[i]);
	scanf("%d",&g);
	for(i=1;i<=g;++i)
	{
		for(j=1;j<=v;++j)scanf("%d",&a[i][j]);
	}
	back(1);
	printf("%d\n",mn);
	for(i=1;i<=mn;++i)printf("%d ",e[i]);
	return 0;
}