#include <stdio.h>
int a[1001];
int main()
{
	int i,n,m,k,x,y;
	scanf("%d%d",&n,&k);
	for(i=1;i<=k;++i)
	{
		scanf("%d%d",&x,&y);
		m=(n+1)/2;
		if(x>m)x=m-x+n/2+1;
		if(y>m)y=m-y+n/2+1;
		if(x>y)
		{
			if(y%3)a[i]=y%3;
			else a[i]=3;
		}
		else if(x%3)a[i]=x%3;
		else a[i]=3;
	}
	for(i=1;i<=k;++i)printf("%d\n",a[i]);
	return 0;
}