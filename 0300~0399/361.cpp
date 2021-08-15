#include <stdio.h>
#include <algorithm>
int a[20001],b[20001];
int main()
{
	int i,n,mn,mi,t;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	std::sort(&a[1],&a[n+1]);
	for(i=1;i<=n;++i)b[i]=b[i-1]+a[i];
	mn=b[n]-n*a[1];
	mi=a[1];
	for(i=2;i<=n;++i)
	{
		t=(i-1)*a[i]-b[i-1]+b[n]-b[i]-(n-i)*a[i];
		if(mn>t)mn=t,mi=a[i];
	}
	printf("%d",mi);
	return 0;
}