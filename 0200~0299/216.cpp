#include <stdio.h>
int a[1001];
int main()
{
	int i,n,k,s,t,r;
	scanf("%d%d",&n,&k);
	for(i=1;i<=k;++i)
	{
		scanf("%d%d%d",&s,&t,&r);
		a[i]=n/s;
		if(n%s)++a[i];
		if(a[i]%t)a[i]+=a[i]/t*r;
		else a[i]+=a[i]/t*r-r;
	}
	for(i=1;i<=k;++i)printf("%d\n",a[i]);
	return 0;
}