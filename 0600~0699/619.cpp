#include <stdio.h>
int main()
{
	int n,m,r;
	__int64 cnt=0,t=1;
	scanf("%d",&n);
	m=n;
	while(m>9)
	{
		r=m%10;
		m/=10;
		if(r!=1)cnt+=(m+(r!=0))*t;
		else cnt+=m*t+n%t+1;
		t*=10;
	}
	if(m>1)cnt+=t;
	else cnt+=n-t+1;
	printf("%d",cnt);
	return 0;
}