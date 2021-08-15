#include <stdio.h>
int a[101],mx=-100001;
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=2;i<=n;++i)a[i]+=a[i-1];
	for(i=1;i<=n;++i)
	{
		for(j=0;j<i;++j)if(mx<a[i]-a[j])mx=a[i]-a[j];
	}
	printf("%d",mx);
	return 0;
}