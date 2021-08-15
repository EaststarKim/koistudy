#include <stdio.h>
int a[257][257];
int main()
{
	int i,j,k,n,m,mn,mx=0,c;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
		{
			scanf("%1d",&a[i][j]);
			if(a[i][j])a[i][j]+=a[i][j-1];
		}
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
		{
			c=0;
			mn=300;
			for(k=i;k>=0;--k)
			{
				if(!a[k][j])break;
				++c;
				if(a[k][j]<mn)mn=a[k][j];
				if(c*mn>mx)mx=c*mn;
			}
		}
	}
	printf("%d",mx);
	return 0;
}