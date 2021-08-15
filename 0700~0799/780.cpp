#include <stdio.h>
int main()
{
	int n,t;
	scanf("%d",&n);
	for(t=1;n>t;t*=2);
	if(t==n)printf("1");
	else printf("%d",(n-t/2)*2+1);
	return 0;
}