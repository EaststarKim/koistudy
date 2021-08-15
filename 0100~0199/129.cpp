#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a[10];

int f(int n, int k);
int main()
{
	int i, n, m, k, l, p;
	scanf("%d",&n);
	p=0;
	k=(int)log10(n)/1;
	m=n;
	for(i=k;i>=0;--i) a[i]=m%10, m/=10;
	l=k/2;
	for(i=0;i<=l;++i) if(a[i]!=a[k-i]) break;
	if(i>l)
	{
		printf("0 %d\n",n);
		exit(0);
	}
	while(1)
	{

		k=(int)log10(n)/1;
		n+=f(n,k);
		++p;
		k=(int)log10(n);
		m=n;
		for(i=k;i>=0;--i) a[i]=m%10, m/=10;
		l=k/2;
		for(i=0;i<=l;++i) if(a[i]!=a[k-i]) break;
		if(i>l) break;
	}
	printf("%d %d\n",p,n);
	return 0;
}
int f(int n, int k)
{
	int x;
	if(n<10) return n;
	x=(int)pow(10, k);
	return f(n/10,k-1)+(n%10)*x;
}