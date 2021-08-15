#include <stdio.h>
#include <math.h>
int main()
{
	int i,j,k,n,p,cnt=0;
	double t;
	scanf("%d",&n);
	for(i=12;i<=n;i+=2)
	{
		p=0;
		for(j=1;j<n;++j)
		{
			for(k=1;k<=j;++k)
			{
				t=sqrt(j*j+k*k);
				if(j+k+t==i)++p;
				if(p>1)break;
			}
			if(p>1)break;
		}
		if(p==1)++cnt;
	}
	printf("%d",cnt);
	return 0;
}