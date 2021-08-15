#include <stdio.h>
int a[100010];
int main()
{
	int i, n, m=0, k=1;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%1d",&a[i]);
	for(i=n;i>=1;--i)m+=a[i]*k, k*=2, k%=3;
	if(m==0 || m%3) printf("False");
	else printf("True");
	return 0;
}