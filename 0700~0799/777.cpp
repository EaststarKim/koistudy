#include <stdio.h>
char c[21][20];
void back(int n)
{
	if(n==1)
	{
		puts(c[n]);
		return;
	}
	back(n-1);
	puts(c[n]);
	back(n-1);
}
int main()
{
	int i,j,n,cnt=0;
	scanf("%d",&n);
	if(n)
	{
		for(i=1;i<=n;++i)
		{
			for(j=0;j<i;++j)c[i][j]='*';
			cnt=cnt*2+i;
		}
		back(n);
	}
	printf("%d",cnt);
	return 0;
}
