#include <stdio.h>
#include <algorithm>
using namespace std;
int a[6];
int main()
{
	int i;
	for(i=1;i<=5;++i)scanf("%d",&a[i]);
	sort(&a[1],&a[6]);
	printf("%d",a[3]);
	return 0;
}