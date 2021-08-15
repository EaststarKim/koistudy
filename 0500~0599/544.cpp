#include <stdio.h>
int a[100001],m,s;
int main()
{
	int i,n,k;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=0;i<k;++i)s+=a[i];
	for(;i<=n;++i)
	{
		s+=a[i]-a[i-k];
		if(m<s)m=s;
	}
	printf("%d",m);
	return 0;
}