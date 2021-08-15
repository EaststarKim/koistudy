#include <stdio.h>
int main()
{
	int i,k,m,s;
	m=s=0;
	for(i=1;i<=4;++i)
	{
		scanf("%d",&k);
		s+=k;
	}
	m+=s/60;
	printf("%d\n%d",m%60,s%60);
	return 0;
}