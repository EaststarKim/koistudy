#include <stdio.h>
#include <string.h>
char c[6];
int main()
{
	int i,a,b,n;
	a=b=1;
	scanf("%s",c);
	n=strlen(c);
	for(i=0;i<n;++i)a*=c[i]-64;
	scanf("%s",c);
	n=strlen(c);
	for(i=0;i<n;++i)b*=c[i]-64;
	if(a%47==b%47)printf("GO");
	else printf("STAY");
	return 0;
}