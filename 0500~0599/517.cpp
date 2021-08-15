#include <stdio.h>
int a[201],x,y,z;
int main()
{
	int i,n,k;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&k);
		a[k]=1;
	}
	x=y=n;
	while(1)
	{
		for(i=z+1;i<=n*2;++i)
		{
			if(a[i]>0)break;
		}
		if(i>n*2)z=0;
		else
		{
			--x;
			z=i;
			a[i]=-1;
		}
		if(x==0)break;
		for(i=z+1;i<=n*2;++i)
		{
			if(!a[i])break;
		}
		if(i>n*2)z=0;
		else
		{
			--y;
			z=i;
			a[i]=-1;
		}
		if(y==0)break;
	}
	printf("%d %d",y,x);
	return 0;
}