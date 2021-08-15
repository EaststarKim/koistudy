#include <stdio.h>
#include <algorithm>
using namespace std;
int a[20001];
int main()
{
	int i,n,b;
	scanf("%d%d",&n,&b);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(&a[1],&a[n+1]);
	for(i=n;i>0;--i)
	{
		b-=a[i];
		if(b<=0)break;
	}
	printf("%d",n-i+1);
	return 0;
}