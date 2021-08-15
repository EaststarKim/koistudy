#include <stdio.h>
int main()
{
	int i,n,k;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i)
	{
		if(n%i==0)--k;
		if(k==0)break;
	}
	if(i>n)printf("0");
	else printf("%d",i);
	return 0;
}