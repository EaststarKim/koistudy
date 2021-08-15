#include <stdio.h>

int main()
{
	int i, j, n;
	scanf("%d",&n);
	if(n==1)
	{
		for(i=1;i<=9;++i)
		{
			for(j=2;j<=9;++j) printf("%d*%d=%d ",j,i,i*j);
			printf("\n");
		}
	}
	else
	{
		for(i=1;i<=9;++i) printf("%d*%d=%d\n",n,i,n*i);
	}
	return 0;
}