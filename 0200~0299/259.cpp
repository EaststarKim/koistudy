#include <stdio.h>
#include <algorithm>
using namespace std;
int a[205],b[205];
int main()
{
	int i,n,m,k,s;
	scanf("%d %d %d",&n,&m,&k);
	for(i=1;i<=k;i++)scanf("%d",&a[i]);
	sort(&a[1],&a[k+1]);
	s=a[k]-a[1]+1;
	for(i=1;i<k;i++)b[i]=a[i+1]-a[i]-1;
	sort(&b[1],&b[k]);
	for(i=k-1;i>k-n&&i>0;--i)s-=b[i];
	printf("%d",s);
	return 0;
}