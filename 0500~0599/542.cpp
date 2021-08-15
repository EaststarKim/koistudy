#include <stdio.h>
#include <math.h>
int a[6];
int main()
{
	int i,j,m;
	__int64 k;
	for(i=1;i<6;++i)
	{
		scanf("%I64d",&k);
		for(j=1;j<k;++j)
		{
			m=(int)pow(10,j);
			if(k<m)break;
		}
		if((k*k-k)%m)a[i]=0;
		else a[i]=1;
	}
	for(i=1;i<6;++i)
	{
		if(a[i])printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}