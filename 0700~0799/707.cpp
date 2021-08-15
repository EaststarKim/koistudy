#include <stdio.h>
#include "lib.h"
int main()
{
	int i,j,m,k;
	scanf("%d",&k);
	for(i=1;i<101;++i)
	{
		for(j=1;j<101;++j)
		{
			m=function(i,j);
			if(m==k)
			{
				printf("%d %d",i,j);
				break;
			}
		}
		if(j<101)break;
	}
	if(i>100)printf("-1");
	return 0;
}
