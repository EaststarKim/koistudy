#include <stdio.h>
int main()
{
	int i,j=1,n;
	__int64 m=1;
	scanf("%d",&n);
	for(i=n*2;i>n+1;--i)
	{
		m*=i;
		for(;j<=n;++j)
		{
			if(m%j==0)m/=j;
			else break;
		}
	}
	printf("%I64d",m);
	return 0;
}