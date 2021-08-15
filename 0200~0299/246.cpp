#include <stdio.h>
int a[16][16]={{1}};
int main()
{
	int i,j,n,m;
	double l;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	{
		l=(double)m/n*i;
		a[i][0]=1;
		for(j=1;j<=l;++j)a[i][j]=a[i-1][j]+a[i][j-1];
	}
	printf("%d",a[n][m]);
	return 0;
}