#include <stdio.h>
int main()
{
	int i,l,n,k,mn=0,mx=0;
	scanf("%d%d",&l,&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&k);
		if(k<l-k)
		{
			if(mx<l-k)mx=l-k;
			if(mn<k)mn=k;
		}
		else
		{
			if(mx<k)mx=k;
			if(mn<l-k)mn=l-k;
		}
	}
	printf("%d %d",mn,mx);
	return 0;
}