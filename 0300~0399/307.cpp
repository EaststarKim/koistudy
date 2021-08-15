#include <stdio.h>
int i,n,k,s,m;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&k);
		if(k)++m;
		else m=0;
		s+=m;
	}
	printf("%d",s);
	return 0;
}