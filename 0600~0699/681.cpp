#include <stdio.h>
#include <math.h>
int main()
{
	int i,j,n,m;
	scanf("%d",&n);
	m=(int)sqrt(n);
	for(i=2;i<=m;++i)
	{
		if(n==1)break;
		for(j=1;j<=100;++j)
		{
			if(n%i)break;
			n/=i;
			printf("%d ",i);
		}
	}
	if(n!=1)printf("%d",n);
	return 0;
}