#include <stdio.h>
int main()
{
	int i,j=2,n,k,x;
	__int64 m=1;
	scanf("%d%d",&n,&k);
	n-=k-1;
	for(i=1;i<=k;++i)
	{
		scanf("%d",&x);
		n-=x;
	}
	k+=n;
	for(i=k;i>k-n;--i)
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