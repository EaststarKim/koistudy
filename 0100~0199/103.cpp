#include <stdio.h>

int main()
{
	double r;
	scanf("%lf",&r);
	r/=2;
	r*=r;
	printf("%.2lf",r*3.14);
	return 0;
}