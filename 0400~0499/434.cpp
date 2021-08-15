#include <stdio.h>
#include <math.h>
int main()
{
	int i,j,n,m,s;
	scanf("%d",&n);
	for(i=n;i>1;--i)
	{
		s=0;
		m=(int)sqrt(i);
		for(j=1;j<=m;++j)
		{
			if(i%j==0)s+=j+i/j;
		}
		if(i==s-i)
		{
			printf("%d",i);
			break;
		}
	}
	return 0;
}