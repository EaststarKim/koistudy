#include <stdio.h>
int main()
{
	int i,k,s=0;
	for(i=1;i<=5;++i)
	{
		scanf("%d",&k);
		s+=k*k;
	}
	printf("%d",s%10);
	return 0;
}