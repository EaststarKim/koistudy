#include <stdio.h>

int main()
{
	int a, b, t;
	scanf("%d %d",&a, &b);
	if(a<b) t=b, b=a, a=t;
	while(a%b)
	{
		t=a%b;
		a=b;
		b=t;
	}
	printf("%d\n",b);
	return 0;
}