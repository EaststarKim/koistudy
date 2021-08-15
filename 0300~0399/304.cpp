#include <stdio.h>
int a[3][100],s;
int main()
{
	int i,j,k,l,n,cnt,x,y;
	scanf("%d",&n);
	for(i=0;i<n;++i)scanf("%d%d%d",&a[0][i],&a[1][i],&a[2][i]);
	for(i=123;i<988;++i)
	{
		if(i%100>9&&i%10&&i%10!=(int)i/100&&i%10!=(int)(i%100)/10&&(int)i/100!=(int)(i%100)/10)
		{
			for(j=0;j<n;++j)
			{
				cnt=0;
				x=i;
				y=a[0][j];
				for(k=1;x;++k)
				{
					if(x%10==y%10)++cnt;
					x/=10;
					y/=10;
				}
				if(cnt!=a[1][j])break;
				cnt=0;
				x=i;
				for(k=1;x;++k)
				{
					y=a[0][j];
					for(l=1;y;++l)
					{
						if(x%10==y%10)break;
						y/=10;
					}
					if(y&&k!=l)++cnt;
					x/=10;
				}
				if(cnt!=a[2][j])break;
			}
			if(j>=n)++s;
		}
	}
	printf("%d",s);
	return 0;
}