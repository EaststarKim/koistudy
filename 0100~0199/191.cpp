#include <stdio.h>
#include <algorithm>
using namespace std;
struct G
{
	int x,y;
	bool operator()(G a,G b)
	{
		return a.y<b.y;
	}
}a[100001];
int cnt;
int main()
{
	int i,n,k=1;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d",&a[i].x,&a[i].y);
	sort(&a[1],&a[n+1],G());
	for(i=2;i<=n;++i)
	{
		if(a[k].y<=a[i].x)
		{
			k=i;
			++cnt;
		}
	}
	printf("%d",cnt+1);
	return 0;
}