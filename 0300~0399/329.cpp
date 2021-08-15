#include <stdio.h>
int main()
{
	int i,j,k,mx=0,mi,mj;
	for(i=1;i<=9;++i)
	{
		for(j=1;j<=9;++j)
		{
			scanf("%d",&k);
			if(mx<k)mx=k,mi=i,mj=j;
		}
	}
	printf("%d\n%d %d",mx,mi,mj);
	return 0;
}