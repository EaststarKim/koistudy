#include <stdio.h>
#include <math.h>
__int64 a[101]={0,1},k=1;
int main()
{
	int i,j,n,m=0;
	scanf("%d",&n);
	for(i=2;i<=n;++i)
	{
		a[i]=172034;
		for(j=1;j<63;++j)
		{
			k=(__int64)pow(2,j)-1;
			k+=2*a[i-j];
			if(a[i]>k)a[i]=k;
		}
	}
	printf("%I64d",a[n]);
	return 0;
}