#include <stdio.h>
int n;
void a(int m)
{
	if(m==1)
	{
		printf("*");
		return ;
	}
	a(m-1);
	printf("*");
}
void b(int m, int sw)
{
	if(m==1)
	{
		printf("*\n");
		return ;
	}
	if(sw==1)
	{
		b(m-1, sw);
		if(m==n)sw=2;
	}
	a(m);
	printf("\n");
	if(sw==2)b(m-1, 2);
}
int main()
{
	scanf("%d",&n);
	b(n, 1);
	return 0;
}