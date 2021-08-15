#include <stdio.h>
#include <math.h>
int main()
{
	int a,b,n,m;
	scanf("%d%d",&a,&b);
	n=(int)sqrt(a-1);
	m=(int)sqrt(b);
	printf("%d",b-a+1-m+n);
	return 0;
}