#include <stdio.h>
int main()
{
	int i,n;
	__int64 a=1,b=2,c;
	scanf("%d",&n);
	if(n==1)b=1;
	for(i=2;i<=n;++i)
	{
		c=a+b;
		a=b;
		b=c;
	}
	printf("%I64d %I64d",b,a);
	return 0;
}