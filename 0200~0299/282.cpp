#include <stdio.h>
__int64 a[10001]={1};
int main()
{
	int i,j,k,n,m;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&k);
		for(j=k;j<=m;++j)
		{
			if(a[j-k])a[j]+=a[j-k];
		}
	}
	printf("%I64d",a[m]);
	return 0;
}