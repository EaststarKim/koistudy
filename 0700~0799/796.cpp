#include <stdio.h>
#define max(a,b) a>b? a:b
int a[1010]={1},max;
int main()
{
	int i,j,n,t,k,l;
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",&k,&l);
		for(j=t-l;j>=0;--j)
		{
			if(a[j])a[j+l]=max(a[j+l],a[j]+k);
		}
	}
	for(i=0;i<=t;++i)
	{
		if(max<a[i])max=a[i];
	}
	printf("%d",max-1);
	return 0;
}