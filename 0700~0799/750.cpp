#include <stdio.h>
int main()
{
	int i,j,t,n,k,s=1800;
	scanf("%d%d",&t,&n);
	for(i=1;i<6;++i)
	{
		for(j=1;j<=n;++j)
		{
			scanf("%d",&k);
			if(k)s+=50;
		}
	}
	if(s+2880<t)printf("I am sleepy");
	else if(t<=s)
	{
		k=(s-t)/50;
		if(t<=1800)k=n*5;
		printf("I can take %d more class",k);
	}
	else printf("I will sleep %d minute",t-s);
	return 0;
}