#include <stdio.h>
#include <algorithm>
using namespace std;
int a[11],b[11];
int main()
{
	int i;
	for(i=1;i<=10;++i)scanf("%d",&a[i]);
	sort(&a[1],&a[11]);
	for(i=1;i<=10;++i)scanf("%d",&b[i]);
	sort(&b[1],&b[11]);
	printf("%d\n",a[10]+a[9]+a[8]);
	printf("%d",b[10]+b[9]+b[8]);
	return 0;
}