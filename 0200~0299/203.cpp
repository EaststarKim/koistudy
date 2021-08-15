#include <stdio.h>
int gcd(int a,int b)
{
	if(a==0)return b;
	if(b==0)return a;
	if(a>b) return gcd(a%b,b);
	return gcd(a,b%a);
}
void main()
{
	int a, b, c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d",gcd(gcd(a,b),c));
}