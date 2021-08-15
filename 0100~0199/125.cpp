#include <stdio.h>
#include <windows.h>

int c[100010];

int main()
{
	int a, b, n, m, t, i, max;
	scanf("%d %d",&a, &b);
	if(a>b) t=a, a=b, b=t;
	for(i=a;i<=b;++i)
	{
		n=i;
		m=n;
		c[m]=1;
		while(n!=1)
		{
			if(n%2) n=n*3+1;
			else n/=2;
			++c[m];
		}
	}
	max=0;
	for(i=a;i<=b;++i)
	{
		if(max<c[i]) max=c[i];
	}
	printf("%d\n",max);
	return 0;
}