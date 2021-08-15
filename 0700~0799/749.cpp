#include <stdio.h>
int main()
{
	int d,n;
	scanf("%d",&d);
	n=d/30+(d%30>14? 1:0);
	if(!n)printf("Too Soon!");
	else printf("%d",n);
	return 0;
}