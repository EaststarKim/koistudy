#include <stdio.h>
int a[2001]={0,0,1};
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=3;i<=n;++i)a[i]=i-1+a[i-3];
	printf("%d",a[n]);
	return 0;
}