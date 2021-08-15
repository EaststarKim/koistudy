#include <stdio.h>
int a[5]={0,10,50,100,500},b[10010];
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=2;i<=n;++i)b[i]=1001;
	for(i=1;i<=4;++i)
	{
		for(j=a[i];j<=n;++j)
		{
			if(b[j]>b[j-a[i]]+1)b[j]=b[j-a[i]]+1;
		}
	}
	printf("%d",b[n]);
	return 0;
}