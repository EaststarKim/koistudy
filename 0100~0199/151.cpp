#include <stdio.h>
int n;
void back(int k)
{
	if(k==1)
	{
		printf("%d*%d=%d\n",n,k,n*k);
		return;
	}
	back(k-1);
	printf("%d*%d=%d\n",n,k,n*k);
}
int main()
{
	scanf("%d",&n);
	back(9);
	return 0;
}