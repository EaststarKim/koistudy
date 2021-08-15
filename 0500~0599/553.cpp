#include <stdio.h>
#include <algorithm>
using namespace std;
int a[101];
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(&a[1],&a[n+1]);
	for(i=n;i>2;--i)
	{
		if(a[i]<a[i-1]+a[i-2])break;
	}
	if(i>2)printf("%d",a[i]+a[i-1]+a[i-2]);
	else printf("0");
	return 0;
}