#include <cstdio>
int a[101][101],chk[101]={0,1},s,mn,mi,mj;
int main()
{
	int i,j,k,n;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)scanf("%d",&a[i][j]);
	}
	for(i=1;i<n;++i)
	{
		mn=100001;
		for(j=1;j<=n;++j)
		{
			if(chk[j])
			{
				for(k=1;k<=n;++k)
				{
					if(a[j][k]&&mn>a[j][k]&&chk[k]==0)mn=a[j][k],mi=j,mj=k;
				}
			}
		}
		s+=mn;
		chk[mj]=1;
	}
	printf("%d",s);
	return 0;
}