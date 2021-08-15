#include <stdio.h>
int a[1001][501];
int main()
{
	int i,j,n,k;
	scanf("%d%d",&n,&k);
	if(k*2>n)printf("0");
	else
	{
		a[0][0]=a[1][0]=a[1][1]=1;
		for(i=2;i<=n;++i)
		{
			for(j=0;j<=(i+1)/2;++j)
			{
				if(j)a[i][j]=(a[i-1][j]+a[i-2][j-1])%1000000003;
				else a[i][j]=1;
			}
		}
		printf("%d",(a[n-3][k-1]+a[n-1][k])%1000000003);
	}
	return 0;
}