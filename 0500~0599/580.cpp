#include <stdio.h>
#include <math.h>
int main()
{
	int j,m;
	__int64 i,n;
	scanf("%I64d",&n);
	for(i=99999999999999997;i>1;i-=2)
	{
		m=(int)sqrt(i);
		for(j=3;j<=m;++j)
		{
			if(i%j==0)break;
		}
		if(j>m)
		{
			printf("%I64d\n%I64d\n%I64d\n%I64d\n%I64d\n",i,i-20,i-36,i-54,i-78);
			break;
		}
	}
	return 0;
}