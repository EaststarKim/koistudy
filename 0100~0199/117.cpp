#include <stdio.h>
#include <math.h>

int a[10010];

int main()
{
	int i, j, n, m, sum;
	scanf("%d",&n);
	a[1]=1;
	for(i=2;i<=n;++i)
	{
		m=int(sqrt(i));
		for(j=2;j<=m;++j)
		{
			if(i%j==0)
			{
				a[i]=1;
				break;
			}
		}
	}
	sum=0;
	for(i=1;i<=n;++i)
	{
		if(a[i]==0) sum+=i;
	}
	printf("%d\n",sum);
	return 0;
}