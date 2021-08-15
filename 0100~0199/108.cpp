#include <stdio.h>

int main()
{
	__int64 n;
	scanf("%lld",&n);
	if((n%400==0)||(n%100 && n%4==0)) printf("Leap\n");
	else printf("Normal\n");
	return 0;
}