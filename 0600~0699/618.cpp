#include <stdio.h>
char a[100],b[1000000];
int main()
{
	int i,j,n,m,cnt=0;
	scanf("%d%d",&n,&m);
	scanf("%s%s",a,b);
	m-=n;
	for(i=0;i<=m;++i)
	{
		for(j=0;j<n;++j)
		{
			if(b[i+j]!=a[j])break;
		}
		if(j==n)++cnt;
	}
	printf("%d",cnt);
	return 0;
}