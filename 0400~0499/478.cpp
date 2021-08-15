#include <stdio.h>
int a[501][501],q[10001],b[501],f,r=1;
int main()
{
	int i,n,m,x,y,z,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		a[x][y]=a[y][x]=z;
	}
	for(i=1;i<=n;++i)b[i]=500001;
	q[1]=1;
	b[1]=0;
	while(f<r)
	{
		k=q[++f];
		for(i=1;i<=n;++i)
		{
			if(a[k][i]&&b[k]+a[k][i]<b[i])
			{
				q[++r]=i;
				b[i]=b[k]+a[k][i];
			}
		}
	}
	if(b[n]<500001)printf("%d",b[n]);
	else printf("Impossible");
	return 0;
}