#include <stdio.h>
int m,cnt;
void p(int n,int m,int k)
{
	int i,j;
	if(n<=0)
	{
		if(n==0)
		{
			++cnt;
			j=1;
		}
		return;
	}
	for(i=m;i>0;--i)p(n-i,i,k+1);
}
int main()
{
	int n;
	scanf("%d%d",&n,&m);
	p(n,m,1);
	printf("%d",cnt);
	return 0;
}