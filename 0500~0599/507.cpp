#include <stdio.h>
int a[1001],b[1001];
int main()
{
	int i,n,m,p=1;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<=m;++i)scanf("%d",&b[i]);
	for(i=1;i<=m;++i)
	{
		p+=b[i];
		p+=a[p];
		if(p<1)p=1;
		if(p>=n)break;
	}
	printf("%d",i);
	return 0;
}