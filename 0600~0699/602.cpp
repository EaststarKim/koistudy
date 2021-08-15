#include <stdio.h>
#include <string.h>
int a[1000001]={1},p,mx;
char b[1000001],c[1000000];
int main()
{
	int i,n;
	scanf("%s",c);
	n=strlen(c);
	b[p]=c[0];
	for(i=1;i<n;++i)
	{
		if(c[i]!=c[i-1])
		{
			a[++p]=1;
			b[p]=c[i];
		}
		else ++a[p];
	}
	for(i=1;i<p;++i)
	{
		if(b[i]=='O')
		{
			if(b[i-1]=='K'&&b[i+1]=='I'&&a[i]<=a[i-1]&&a[i]<=a[i+1]&&mx<a[i])mx=a[i];
		}
	}
	printf("%d",mx);
	return 0;
}