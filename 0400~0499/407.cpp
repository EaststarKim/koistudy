#include <stdio.h>
int main()
{
	int i,n,m,k;
	__int64 s=0;
	scanf("%d",&n);
	m=(n-1)/2;
	k=n/3;
	if(n%3)++k;
	for(i=m;i>=k;--i)s+=(i*3-n)/2+1;
	printf("%I64d",s);
	return 0;
}