#include <stdio.h>
int k;
void f(int n)
{
	if(n<k) 
	{
		printf("%X",n);
		return ;
	}
	f(n/k);
	printf("%X",n%k);
}
int main()
{
	int n;
	scanf("%d",&n);
	k=2;
	printf("2 ");
	f(n);
	printf("\n");
	k=8;
	printf("8 ");
	f(n);
	printf("\n");
	k=16;
	printf("16 ");
	f(n);
	return 0;
}