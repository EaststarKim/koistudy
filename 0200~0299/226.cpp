#include <stdio.h>
int main()
{
	int i,k,s=0;
	for(i=1;i<=7;++i)
	{
		scanf("%d",&k);
		if(k%2)s+=k;
	}
	if(s)printf("%d",s);
	else printf("-1");
	return 0;
}