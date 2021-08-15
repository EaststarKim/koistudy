#include <stdio.h>
int a[100001]={1,1};
int main()
{
	int i,n,m;
	scanf("%d%d",&n,&m);
	for(i=2;i<=n;++i)a[i]=(a[i-1]+a[i-2])%m;
	printf("%d",a[n]%m);
	return 0;
}