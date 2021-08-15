#include <stdio.h>
#include <string.h>

char a[50];

int main()
{
	int i, n, m;
	char c;
	fgets(a,50,stdin);
	n=strlen(a);
	m=n/2;
	for(i=0;i<m;++i) c=a[i],a[i]=a[n-i-1],a[n-i-1]=c;
	for(i=0;i<n;++i) printf("%c",a[i]);
	return 0;
}