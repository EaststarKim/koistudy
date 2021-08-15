#include <stdio.h>
#include <math.h>
void h(int n, char s, char m, char d);
int main()
{
	int n, k;
	scanf("%d",&n);
	k=(int)pow(2,n);
	printf("%d\n",k-1);
	h(n, 65, 66, 67);
	return 0;
}
void h(int n, char s, char m, char d)
{
	if(n==1) printf("move disk 1 %c->%c\n",s, d);
	else
	{
		h(n-1, s, d, m);
		printf("move disk %d %c->%c\n",n, s, d);
		h(n-1, m, s, d);
	}
}