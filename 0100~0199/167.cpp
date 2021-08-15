#include <stdio.h>
int a[10010];
int main()
{
	int i,j,n,m,k;
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;++i)a[i]=m+1;
	for(i=1;i<=n;++i)
	{
		scanf("%d",&k);
		for(j=k;j<=m;++j)
		{
			if(a[j]>a[j-k]+1)a[j]=a[j-k]+1;
		}
	}
	printf("%d",a[m]);
	return 0;
}