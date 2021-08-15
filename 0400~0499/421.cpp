#include <stdio.h>
#include <string.h>
char a[10],b[10];
int main()
{
	int i,j,k,n,m,cnt=0;
	scanf("%s",a);
	m=strlen(a);
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%s",b);
		for(j=0;j<10;++j)
		{
			for(k=0;k<m;++k)
			{
				if(a[k]!=b[(j+k)%10])break;
			}
			if(k==m)
			{
				++cnt;
				break;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}