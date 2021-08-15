#include <stdio.h>
int a[110][110],mx;
int main()
{
	int i,j,k,l,n,m,s,mi,mj;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)scanf("%d",&a[i][j]);
	}
	for(i=1;i<n-1;++i)
	{
		for(j=1;j<m-1;++j)
		{
			s=0;
			for(k=0;k<3;++k)
			{
				for(l=0;l<3;++l)s+=a[i+k][j+l];
			}
			if(mx<s)mx=s,mi=i,mj=j;
		}
	}
	printf("%d\n%d %d",mx,mi,mj);
	return 0;
}