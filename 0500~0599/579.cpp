#include<stdio.h>
int main()
{
	int n,k,c;
	scanf("%d%d",&n,&k);
	n--;
	while(1)
	{
		if(n<k)break;
		c+=(n/k);
		n=(n%k)+(n/k);
	}
	if(n!=0)c++;
	printf("%d",c);
	return 0;
}