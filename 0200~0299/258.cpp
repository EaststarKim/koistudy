#include <stdio.h>
int a[33];
int main()
{
	int i,j,n,s,l,p,cnt;
	scanf("%d%d",&n,&s);
	while(n)
	{
		++s;
		cnt=0;
		for(i=2;i<11;++i)
		{
			l=s;
			p=0;
			while(l/i||l%i)
			{
				a[++p]=l%i;
				l/=i;
			}
			for(j=1;j<=p/2;++j)
			{
				if(a[j]!=a[p-j+1])break;
			}
			if(j>p/2)++cnt;
			if(cnt>1)break;
		}
		if(i<11)
		{
			printf("%d\n",s);
			--n;
		}
	}
	return 0;
}
