#include <stdio.h>
int a[41];
int main()
{
	int i,j,n,m;
	scanf("%d",&n);
	a[2]=a[3]=-1;
	for(i=4;i<=n;++i)
	{
		if(i%3)m=i/3;
		else m=i/3-1;
		for(j=1;j<=m;++j)
		{
			if(a[i-j]<0||a[i-j]>j*2)break;
		}
		if(j>m)a[i]=-1;
		else a[i]=j;
	}
	printf("%d",a[n]);
	return 0;
}