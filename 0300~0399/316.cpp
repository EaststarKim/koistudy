#include <stdio.h>
int a[101][101],s;
int main()
{
	int i,j,k,n,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",&x,&y);
		for(j=x;j<x+10;++j)
		{
			for(k=y;k<y+10;++k)a[j][k]=1;
		}
	}
	for(i=1;i<101;++i)
	{
		for(j=1;j<101;++j)
		{
			if(a[i][j]==1)++s;
		}
	}
	printf("%d",s);
	return 0;
}