#include <stdio.h>
int a[5001],b[5001],c[5001],d[5001],cnt=1;
int main()
{
	int i,j,n,m,t;
	scanf("%d%d%d",&n,&m,&t);
	for(i=1;i<=m;++i)scanf("%d%d%d",&a[i],&b[i],&c[i]);
	d[1]=t;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
		{
			if(b[j]==t||c[j]==t)
			{
				t=a[j];
				break;
			}
		}
		d[++cnt]=t;
		if(t==1)break;
	}
	printf("%d\n",cnt);
	for(i=cnt;i>0;--i)printf("%d\n",d[i]);
	return 0;
}