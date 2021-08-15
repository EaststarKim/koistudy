#include <stdio.h>
int b[3][3001],t;
int main()
{
	int i,n,l,k,f=1;
	scanf("%d%d",&n,&l);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",&k,&b[0][i]);
		if(b[0][i])
		{
			b[1][i]=l-k+1;
			b[2][i]=l;
		}
		else
		{
			b[1][i]=1;
			b[2][i]=k;
		}
	}
	while(f<n)
	{
		for(i=b[1][f];i<=b[2][f];++i)
		{
			if((b[1][f+1]<=i&&i<=b[2][f+1])||b[1][f+1]==i+1||b[2][f+1]==i-1)break;
		}
		if(i>b[2][f])
		{
			for(i=f;i<=n;++i)
			{
				if(b[1][i]>1||b[2][i]<l)
				{
					if((b[0][i]&&b[1][i]==1)||(!b[0][i]&&b[2][i]!=l))
					{
							b[0][i]=0;
							++b[1][i];
							++b[2][i];
					}
					else
					{
						b[0][i]=1;
						--b[1][i];
						--b[2][i];
					}
				}
			}
			++t;
		}
		else ++f;
	}
	printf("%d",t);
	return 0;
}

