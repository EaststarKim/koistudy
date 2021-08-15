#include <stdio.h>
__int64 a[90];
void f(int n)
{
	if(n<3)
	{
		a[n]=1;
		return;
	}
	if(a[n-1]==0)f(n-1);
	if(a[n-2]==0)f(n-2);
	a[n]=a[n-1]+a[n-2];
}
int main()
{
	int n;
	scanf("%d",&n);
	f(n);
	printf("%I64d",a[n]);
	return 0;
}