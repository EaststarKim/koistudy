#include <stdio.h>

int main()
{
	double n1, n2, n3;
	double ave;
	scanf("%lf %lf %lf",&n1, &n2, &n3);
	ave=(n1+n2+n3)/3;
	printf("%.3lf\n",ave);
	return 0;
}