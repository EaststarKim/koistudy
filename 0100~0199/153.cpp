#include <stdio.h>
#include <math.h>
int m;
int f(int n, int k)
{
	if(n<10)return n;
	m=(int)pow(10,k);
	return m*(n%10)+f(n/10, k-1);
}
int main()
{
	int n, k=0;
	scanf("%d",&n);
	k=(int)log10(n);
	printf("%d",f(n, k));
	return 0;
}