#include <stdio.h>
int a[10001],s,k;
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		s+=a[i];
	}
	s/=n;
	for(i=1;i<=n;++i)
	{
		if(a[i]>s)k+=a[i]-s;
	}
	printf("%d",k);
	return 0;
}