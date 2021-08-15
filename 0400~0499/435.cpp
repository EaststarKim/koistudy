#include <stdio.h>
int main()
{
	__int64 a,b,x,y,t;
	scanf("%I64d%I64d",&a,&b);
	x=a;
	y=b;
	while(x%y)
	{
		t=x%y;
		x=y;
		y=t;
	}
	printf("%I64d",a*b/y);
	return 0;
}