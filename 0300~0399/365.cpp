#include <stdio.h>
int a[100010];
int gcd(int x,int y)
{
	if(x%y==0)return y;
	return gcd(y,x%y);
}
int main()
{
	int i,n,e;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	e=a[n];
	for(i=n;i>1;--i)a[i]-=a[i-1];
	for(i=3;i<=n;++i)
	{
		a[i]=gcd(a[i-1],a[i]);
	}
	printf("%d",(e-a[1])/a[n]-n+1);
	return 0;
}