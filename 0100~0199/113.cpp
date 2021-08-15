#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c, x1, x2;
	scanf("%lf %lf %lf",&a, &b, &c);
	if(b*b-4*a*c<0) printf("none.\n");
	else
	{
		x1=(-b+sqrt(b*b-4*a*c))/(2*a);
		x2=(-b-sqrt(b*b-4*a*c))/(2*a);
		if(x1==x2) printf("%g\n",x1);
		else if(x1<x2) printf("%g %g\n",x2,x1);
		else if(x1>x2) printf("%g %g\n",x1,x2);
	}
	return 0;
}