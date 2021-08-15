#include <stdio.h>
int main()
{
	int i;
	__int64 n,k,m=1;
	scanf("%I64d%I64d",&n,&k);
	if(n>1)
	{
		for(i=1;i<=n;++i)m=m*(k-1)%1000000007;
		if(n%2)m-=k-1;
		else m=(m+k-1)%1000000007;
	}
	else m=k;
	printf("%I64d",m);
	return 0;
}