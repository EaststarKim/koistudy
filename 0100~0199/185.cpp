#include <stdio.h>
int main()
{
	int i,j=1,n,k;
	__int64 m=1;
	scanf("%d%d",&n,&k);
	for(i=n;i>n-k;--i)
	{
		m*=i;
		for(;j<=k;++j)
		{
			if(m%j==0)m/=j;
			else break;
		}
	}
	printf("%I64d",m);
	return 0;
}