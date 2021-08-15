#include <stdio.h>
#include <algorithm>
using namespace std;
struct G
{
	int x,y;
	bool operator()(G a,G b)
	{
		return a.x<b.x;
	}
}a[5001];
int main()
{
	int i,n,k,s;
	scanf("%d%d",&n,&k);
	for(i=1;i<=k;++i)scanf("%d%d",&a[i].x,&a[i].y);
	sort(&a[1],&a[k+1],G());
	s=0;
	for(i=1;n>0;++i)
	{
		if(a[i].y>n)s+=a[i].x*n,n=0;
		else s+=a[i].x*a[i].y,n-=a[i].y;
	}
	printf("%d",s);
	return 0;
}