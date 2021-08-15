#include <stdio.h>
int main()
{
	int i,k,mx=0,mj;
	for(i=1;i<=9;++i)
	{
		scanf("%d",&k);
		if(mx<k)mx=k,mj=i;
	}
	printf("%d\n%d",mx,mj);
	return 0;
}