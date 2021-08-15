#include <stdio.h>
int a[1010][1010],b[1010][1010],q[2][1000010];
int f,r=1,ro,co;
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)scanf("%d",&a[i][j]),b[i][j]=-210000000;
	q[0][1]=q[1][1]=1;
	b[1][1]=a[1][1];
	while(f<r)
	{
		ro=q[0][++f];
		co=q[1][f];
		if(ro<n&&b[ro][co]+a[ro+1][co]>b[ro+1][co])
		{
			q[0][++r]=ro+1;
			q[1][r]=co;
			b[ro+1][co]=b[ro][co]+a[ro+1][co];
		}
		if(co<n&&b[ro][co]+a[ro][co+1]>b[ro][co+1])
		{
			q[0][++r]=ro;
			q[1][r]=co+1;
			b[ro][co+1]=b[ro][co]+a[ro][co+1];
		}
	}
	printf("%d",b[n][n]);
	return 0;
}