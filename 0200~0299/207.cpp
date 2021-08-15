#include <stdio.h>
#include <string.h>
char a[11],b[11],k,s;
int main()
{
	int i,n,m;
	scanf("%s",a);
	scanf("%s",b);
	n=strlen(a);
	m=strlen(b);
	for(i=0;i<n;++i)k+=a[i]-48;
	for(i=0;i<m;++i)s+=b[i]-48;
	printf("%d",k*s);
	return 0;
}