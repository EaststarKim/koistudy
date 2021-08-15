#include <stdio.h>
#include <math.h>
int main()
{
	int i,j,m,k;
	__int64 n,s,p,t=1;
	scanf("%I64d",&n);
	m=(int)sqrt((double)n);
	for(i=2;i<=m;++i)
	{
		k=0;
		while(n%i==0)n/=i,++k;
		s=p=1;
		for(j=1;j<=k;++j)s*=i,p+=s;
		t*=p;
	}
	if(n!=1)t*=n+1;
	printf("%I64d",t);
	return 0;
}