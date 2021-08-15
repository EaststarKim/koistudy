#include <stdio.h>
int main()
{
	int i,n,k,s=0,mn=101;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&k);
		s+=k;
		if(mn>k)mn=k;
	}
	printf("%d",s-mn);
	return 0;
}