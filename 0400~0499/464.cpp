#include <stdio.h>
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	b+=(a-11)*24;
	c+=(b-11)*60-11;
	if(c<0)printf("-1");
	else printf("%d",c);
	return 0;
}