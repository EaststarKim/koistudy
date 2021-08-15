#include <stdio.h>
int a[30];
void p(int n,int m,int k)
{
	int i,j;
	if(n<=0)
	{
		if(n==0)
		{
			for(j=1;j<k;++j)printf("%d ",a[j]);
			printf("\n");
			j=1;
		}
		return;
	}
	for(i=m;i>0;--i)
	{
		a[k]=i;
		p(n-i,i,k+1);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	p(n,n,1);
	return 0;
}