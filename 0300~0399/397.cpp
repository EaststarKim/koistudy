#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100001];
bool s(int x,int y)
{
	return abs(x)<abs(y);
}
int main()
{
	int i,n,p,min=2000000001;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(&a[1],&a[n+1],s);
	for(i=1;i<n;++i)
	{
		if(abs(a[i]+a[i+1])<min)
		{
			p=i;
			min=abs(a[i]+a[i+1]);
		}
	}
	if(a[p]>a[p+1])printf("%d %d",a[p+1],a[p]);
	else printf("%d %d",a[p],a[p+1]);
	return 0;
}