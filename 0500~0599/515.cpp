#include <stdio.h>
#include <string.h>
char a[10000];
int main()
{
	int i,n,m=0,k=0;
	scanf("%s",a);
	n=strlen(a);
	for(i=2;i<n;++i)
	{
		if(a[i-1]=='O'&&a[i]=='I')
		{
			if(a[i-2]=='K')++m;
			if(a[i-2]=='I')++k;
		}
	}
	printf("%d\n%d",m,k);
	return 0;
}