#include <stdio.h>
int main()
{
	int i,n;
	__int64 s=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)s+=i*(i+1)/2;
	printf("%I64d",s);
	return 0;
}