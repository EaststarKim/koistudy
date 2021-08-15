#include <stdio.h>
int main()
{
	int t,a,b,c,d;
	scanf("%d%d%d%d%d",&t,&a,&b,&c,&d);
	a=(a+c-1)/c;
	b=(b+d-1)/d;
	if(a<b)printf("%d",t-b);
	else printf("%d",t-a);
	return 0;
}