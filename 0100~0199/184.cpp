#include <stdio.h>
int k;
void f(int n)
{
	if(n<k)
	{
		printf("%X",n);
		return;
	}
	f(n/k);
	printf("%X",n%k);
}
int main()
{
	int i;
	long double n;
	scanf("%Lf%d",&n,&k);
	f((int)n/1);
	n-=(int)n/1;
	printf(".");
	for(i=1;i<11;++i)
	{
	
		if(n==0)break;
		n*=k;
		printf("%X",(int)n/1);
		n-=(int)n/1;
	}
	if(i==1)printf("0");
	return 0;
}