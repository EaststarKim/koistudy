#include <stdio.h>

int main()
{
	int n1, n2, n3, t;
	scanf("%d %d %d",&n1, &n2, &n3);
	if(n1==n2||n2==n3||n3==n1) printf("Impossible\n");
	else
	{
		if(n1>n2) t=n2,	n2=n1, n1=t;
		if(n1>n3) t=n3, n3=n1, n1=t;
		if(n2>n3) t=n3, n3=n2, n2=t;
		printf("%d %d %d\n",n1, n2, n3);
	}
	return 0;
}