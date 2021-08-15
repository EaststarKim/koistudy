#include <stdio.h>
int main()
{
	int i,a,b,cnt=0;
	scanf("%d%d",&a,&b);
	for(i=1;i*i*i*i*i*i<=b;++i)if(i*i*i*i*i*i>=a)++cnt;
	printf("%d",cnt);
	return 0;
}
