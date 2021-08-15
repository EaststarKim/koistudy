#include <stdio.h>
int main()
{
	int i,j,n,m,k,t,s,c;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",&t,&s);
		c=0;
		m=s*s;
		for(j=1;j<=m;++j)
		{
			scanf("%d",&k);
			if(k)++c;
		}
		if(t)
		{
			if(c%2)printf("pass\n");
			else printf("fail\n");
		}
		else
		{
			if(c%2)printf("fail\n");
			else printf("pass\n");
		}
	}
	return 0;
}