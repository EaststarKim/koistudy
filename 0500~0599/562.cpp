#include <stdio.h>
#include <math.h>
int main()
{
	int i,n,m,k,a,b,t;
	scanf("%d%d",&n,&m);
	m/=n;
	k=(int)sqrt(m);
	for(i=k;i>0;--i)
	{
		if(m%i==0)
		{
			a=m/i;
			b=i;
			while(a%b)
			{
				t=a%b;
				a=b;
				b=t;
			}
			if(b==1)
			{
				printf("%d %d",n*i,n*m/i);
				break;
			}
		}
	}
	return 0;
}