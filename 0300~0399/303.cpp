#include <stdio.h>
int a[30]={0,1,1};
int main()
{
	int i,n,k;
	scanf("%d%d",&n,&k);
	for(i=2;i<n;++i)a[i]=a[i-1]+a[i-2];
	for(i=1;(k-a[n-2]*i)%a[n-1];++i);
	printf("%d\n%d",i,(k-a[n-2]*i)/a[n-1]);
	return 0;
}