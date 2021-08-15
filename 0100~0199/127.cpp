#include <stdio.h>

int main()
{
	int n1, n2, n3;
	scanf("%d %d",&n1, &n2);
	n3=0;
	while(n1)
	{
		if(n1%2) n3+=n2;
		n1=n1>>1;
		n2=n2<<1;
	}
	printf("%d\n",n3);
	return 0;
}