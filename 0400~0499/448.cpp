#include <stdio.h>
int a[8],chk[8],n;
void back(int p)
{
	int i;
	if(p>n)
	{
		for(i=1;i<=n;++i)printf("%d",a[i]);
		printf("\n");
	}
	for(i=n;i>0;--i)
	{
		if(chk[i]==0)
		{
			a[p]=i;
			chk[i]=1;
			back(p+1);
			a[p]=chk[i]=0;
		}
	}
}
int main()
{
	int i,m=1;
	scanf("%d",&n);
	for(i=2;i<=n;++i)m*=i;
	printf("%d\n",m);
	back(1);
	return 0;
}