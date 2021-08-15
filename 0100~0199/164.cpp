#include <stdio.h>
int a[710];
int main()
{
	int i,n,m,k,mx=0,s=0;
	scanf("%d%d",&n,&m);
	m=n-m;
	for(i=1;i<=n;++i)
	{
		scanf("%d",&k);
		++a[k];
		if(mx<k)mx=k;
	}
	for(i=1;i<=mx;++i)
	{
		if(m==0)break;
		if(m<a[i])s+=m*i,m=0;
		else s+=a[i]*i,m-=a[i];
	}
	printf("%d",s);
	return 0;
}