#include <stdio.h>
int main()
{
	int x,y,t;
	scanf("%d%d",&x,&y);
	if(x>y)t=x,x=y,y=t;
	--x;
	printf("%d",y/4-x/4-y/100+x/100+y/400-x/400);
	return 0;
}