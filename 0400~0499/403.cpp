#include <stdio.h>
#include <math.h>
int a[244];
int main()
{
	int j,n,m,k,s,t;
	scanf("%d",&n);
	for(;n>0;--n)
	{
		m=n;
		while(m>1)
		{
			s=0;
			k=(int)log10(m);
			t=m;
			for(j=0;j<=k;++j)
			{
				s+=(t%10)*(t%10);
				t/=10;
			}
			a[m]=s;
			m=s;
			if(a[m])break;
		}
		if(!a[m])
		{
			printf("%d",n);
			return 0;
		}
	}
	return 0;
}
