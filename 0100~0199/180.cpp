#include <stdio.h>
int a[2001];
int main()
{
	int i,n,k,t;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		k=i;
		while(k>1)
		{
			if(a[k/2]<a[k])
			{
				t=a[k/2];
				a[k/2]=a[k];
				a[k]=t;
				k/=2;
			}
			else break;
		}
	}
	for(i=1;i<=n;++i)printf("%d ",a[i]);
	return 0;
}