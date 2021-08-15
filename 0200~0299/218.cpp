#include <stdio.h>
#include <algorithm>
using namespace std;
struct G
{
	int x,y,z;
	bool operator()(G a,G b)
	{
		return a.x>b.x;
	}
}a[50001];
int main()
{
	int i,n,k,t;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].z=i;
	}
	sort(&a[1],&a[n+1],G());
	for(i=1;i<=k;++i)
	{
		t=a[i].x;
		a[i].x=a[i].y;
		a[i].y=t;
	}
	sort(&a[1],&a[k+1],G());
	printf("%d",a[1].z);
	return 0;
}
