#include <stdio.h>
int a[97];
int main()
{
	int i,n,p,k,m;
	scanf("%d%d",&n,&p);
	k=n;
	for(i=0;i<=p;++i)
	{
		m=k*n%p;
		if(a[m])break;
		a[m]=a[k]+1;
		k=m;
	}
	printf("%d",a[k]-a[m]+1);
	return 0;
}

