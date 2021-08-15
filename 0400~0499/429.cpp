#include <stdio.h>
#include <algorithm>
using namespace std;
int a[20],b[20];
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]),b[i]=a[i];
	sort(&a[1],&a[n+1]);
	for(i=1;i<=n;++i)
	{
		if(a[n/2+1]==b[i])break;
	}
	printf("%d",i);
	return 0;
}