#include <stdio.h>

int main()
{
	int a, b, c, mxl;
	scanf("%d %d %d",&a, &b, &c);
	if(b<a && c<a) mxl=a;
	else if(a<b && c<b) mxl=b;
	else mxl=c;
	if(a+b+c-mxl<=mxl) printf("Not\n");
	else
	{
		if(a==b && b==c) printf("Regular\n");
		else if(a==b||a==c||b==c) printf("Isosceles\n");
		else if(mxl*mxl==a*a+b*b+c*c-mxl*mxl) printf("Right\n");
		else printf("Normal\n");
	}
	return 0;
}