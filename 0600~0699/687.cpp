#include <stdio.h>
int main()
{
	int n,s=0,t=1;
	scanf("%d",&n);
	while(n)
	{
		if(n%10>3)s+=(n%10-1)*t;
		else s+=n%10*t;
		n/=10;
		t*=9;
	}
	printf("%d",s);
	return 0;
}