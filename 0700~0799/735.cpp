#include <stdio.h>
#include <string.h>
char a[30],c[110];
int main()
{
	int i,j,k,l,n,m,t,cnt=0,sw;
	scanf("%d %s",&n,a);
	m=strlen(a)-1;
	for(i=1;i<=n;++i)
	{
		scanf(" %s",c);
		t=strlen(c);
		sw=0;
		for(j=0;j<t;++j)
		{
			if(c[j]==a[0])
			{
				for(k=1;k<t;++k)
				{
					if(j+k*m>=t)break;
					for(l=1;l<=m;++l)
					{
						if(c[j+k*l]!=a[l])break;
					}
					if(l>m)
					{
						++cnt;
						sw=1;
						break;
					}
				}
				if(sw)break;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}