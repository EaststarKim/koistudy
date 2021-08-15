#include <stdio.h>
#include <algorithm>
using namespace std;
int a[11];
int main()
{
	int i,k;
	for(i=1;i<11;++i)scanf("%d",&a[i]);
	scanf("%d",&k);
	k=a[k];
	sort(&a[1],&a[11]);
	for(i=1;i<11;++i)if(a[i]==k)break;
	if(i>9)printf("WINNER");
	else if(i>7)printf("GOLD");
	else if(i>4)printf("SILVER");
	else printf("BRONZE");
	return 0;
}