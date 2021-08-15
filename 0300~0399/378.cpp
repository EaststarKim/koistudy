#include <stdio.h>
#include <math.h>
int main()
{
	int i,j,n,k,m;
	scanf("%d%d",&n,&k);
	m=(int)pow(2,n);
	for(i=0;i<=n;++i)
	{
		m/=2;
		if(m==0)
		{
			printf("K");
			break;
		}
		if(m<k)
		{
			for(j=1;j<=m;++j)printf("I");
			k-=m;
		}
		else
		{
			for(j=1;j<=m;++j)printf("K");
			for(j=1;j<=m;++j)printf("O");
			break;
		}
	}
	return 0;
}