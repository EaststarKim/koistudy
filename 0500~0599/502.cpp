#include <stdio.h>
int main()
{
	int cnt=1,n;
	__int64 i;
	scanf("%d",&n);
	for(i=2;i<n;++i)
	{
		if(n>=i*(i+1)/2&&(n-i*(i+1)/2)%i==0)++cnt;
	}
	printf("%d",cnt);
	return 0;
}