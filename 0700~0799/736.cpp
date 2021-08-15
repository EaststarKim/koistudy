#include <stdio.h>
#include <algorithm>
int a[210][210],t[210],c[210][3],mx;
int main()
{
	int i,j,k,d,n,s;
	scanf("%d%d",&d,&n);
	for(i=1;i<=d;++i)scanf("%d",&t[i]);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d%d",&c[i][0],&c[i][1],&c[i][2]);
		if(t[1]<c[i][0]||t[1]>c[i][1])a[1][i]=-1;
	}
	for(i=2;i<=d;++i)
	{
		for(j=1;j<=n;++j)
		{
			if(t[i]<c[j][0]||t[i]>c[j][1])
			{
				a[i][j]=-1;
				continue;
			}
			for(k=1;k<=n;++k)
			{
				s=abs(c[k][2]-c[j][2]);
				if(a[i-1][k]>=0&&a[i-1][k]+s>a[i][j])a[i][j]=a[i-1][k]+s;
			}
		}
		
	}
	for(i=1;i<=n;++i)
	{
		if(mx<a[d][i])mx=a[d][i];
	}
	printf("%d",mx);
	return 0;
}