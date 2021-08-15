#include <stdio.h>
#include <algorithm>
struct data
{
	int x,y;
	bool operator<(const data&r)const{
		return x<r.x;
	}
}a[100010];
int main()
{
	int i,n,m,s=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)scanf("%d%d",&a[i].x,&a[i].y);
	std::sort(&a[1],&a[m+1]);
	for(i=1;i<=m;++i)
	{
		if(i!=m/2+1)
		{
			s+=abs(a[m/2+1].x-a[i].x);
			std::swap(a[i].x,a[i].y);
		}
	}
	std::swap(a[m/2+1].x,a[m/2+1].y);
	std::sort(&a[1],&a[m+1]);
	for(i=1;i<=m;++i)s+=abs(a[m/2+1].x-a[i].x);
	printf("%d",s);
	return 0;
}
