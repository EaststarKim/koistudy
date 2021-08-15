#include <stdio.h>

int gcd(int a, int b);

void main()
{
	int a, b;
	scanf("%d%d",&a, &b);
	printf("%d",gcd(a, b));
}
int gcd(int a, int b)
{
	if(a==b) return a;
	if(a>b) return gcd(a-b, b);
	return gcd(a, b-a);
}