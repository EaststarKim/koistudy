#include <stdio.h>
int main()
{
	int i;
	__int64 m,k,s=0;
	scanf("%I64d",&m);
	for(i=1;i<11;++i)
	{
		scanf("%I64d",&k);
		s+=((k%m)*2)%m;
		s%=m;
	}
	printf("%I64d",s);
	return 0;
}