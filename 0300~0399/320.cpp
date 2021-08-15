#include <stdio.h>
int a[110][110],cnt;
int main()
{
	int i,j,k,n,r,c;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",&r,&c);
		for(j=0;j<10;++j)
		{
			for(k=0;k<10;++k)a[r+j][c+k]=1;
		}
	}
	for(i=1;i<101;++i)
	{
		for(j=1;j<101;++j)
		{
			if(a[i][j])
			{
				if(!a[i-1][j])++cnt;
				if(!a[i][j+1])++cnt;
				if(!a[i+1][j])++cnt;
				if(!a[i][j-1])++cnt;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}