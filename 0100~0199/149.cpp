#include <stdio.h>
void back(int n, int sw)
{
	if(n==1)
	{
		printf("*");
		return ;
	}
	if(sw==1)
	{
		back(n-1, 1);
		printf("\n");
	}
	back(n-1, 0);
	printf("*");
}
int main()
{
	int n;
	scanf("%d",&n);
	back(n, 1);
	return 0;
}
