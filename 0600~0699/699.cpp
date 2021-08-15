#include <stdio.h>
int main()
{
	int n,s=-1;
	scanf("%d",&n);
	if(n%2)s+=(n-1)/2*((n-1)/2+1)*2+(n/2+1)*2;
	else s+=n/2*(n/2+1)*2;
	printf("%d",s);
	return 0;
}