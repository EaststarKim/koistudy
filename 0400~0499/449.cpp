#include <stdio.h>
int main()
{
	int i,mx,s,a,b;
	mx=s=0;
	for(i=1;i<=4;++i)
	{
		scanf("%d %d",&a,&b);
		s+=b-a;
		if(mx<s)mx=s;
	}
	printf("%d",mx);
	return 0;
}