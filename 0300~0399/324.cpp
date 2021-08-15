#include <stdio.h>
int d[101][101];
int main()
{
	int i,j,k,n,a,b,min,max=100,c;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",&a,&b);
		for(j=a;j<a+10;++j)
		{
			for(k=b;k<b+10;++k)d[j][k]=1;
		}
	}
	for(j=1;j<101;++j)
	{
		for(k=1;k<101;++k)
		{
			if(d[j][k]!=0)d[j][k]+=d[j][k-1];
		}
	}
	for(i=1;i<101;++i)
	{
		for(j=1;j<101;++j)
		{
			c=0;
			min=999;
			for(k=0;k<i;++k)
			{
				if(d[i-k][j]==0)break;
				else ++c;
				if(d[i-k][j]<min)min=d[i-k][j];
				if(c*min>max)max=c*min;
			}
		}
	}
	printf("%d",max);
	return 0;
}

