#include <stdio.h>
int a[10002],mx;
int main()
{
	int i,j,n,x,y,k;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d%d",&x,&k,&y);
		if(mx<y)mx=y;
		for(j=x;j<y;++j)
		{
			if(a[j]<k)a[j]=k;
		}
	}
	for(i=1;i<=mx;++i)
	{
		if(a[i]!=a[i-1])printf("%d %d\n",i,a[i]);
	}
	return 0;
}