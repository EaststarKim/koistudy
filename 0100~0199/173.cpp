#include <stdio.h>
int main()
{
	int i,n,s=1;
	scanf("%d",&n);
	for(i=1;i<=n;++i)s+=i*3+1,s%=1000000004;
	printf("%d",s);
	return 0;
}