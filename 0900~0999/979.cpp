#include <stdio.h>
int a[1000010],s;
char c[1000010];
int main()
{
	int i,n,m;
	scanf("%d%d",&n,&m);
	scanf(" %s",c+1);
	for(i=2;i<m;++i)
	{
		if(c[i]==79&&c[i-1]==73&&c[i+1]==73)a[i]=a[i-2]+1;
		if(a[i]>=n)++s;
	}
	printf("%d",s);
	return 0;
}
