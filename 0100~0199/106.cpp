#include <stdio.h>

int main()
{
	__int64 a, b;
	scanf("%I64d %I64d",&a,&b);
	if(a<b) printf("%I64d\n",b);
	else printf("%I64d\n",a);
	return 0;
}