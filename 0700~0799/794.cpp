#include<cstdio>
#include<algorithm>
int a[1000010],b[1000010];
long long s;
int main()
{
	int i,n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<=n;++i)scanf("%d",&b[i]);
	std::sort(&a[1],&a[n+1]);
	std::sort(&b[1],&b[n+1]);
	for(i=n;i>y;--i)s-=a[i]*b[i];
	for(i=1;i<=y;++i)s+=a[i]*b[y-i+1];
	printf("%d",(s%10000000+10000000)%10000000);
	return 0;
}
