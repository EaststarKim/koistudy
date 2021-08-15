#include <stdio.h>
#include <string.h>
char a[1000000],c='A';
int main()
{
	int i,n;
	scanf("%s",a);
	n=strlen(a);
	for(i=0;i<n;++i)
	{
		if(c=='A')c+=a[i]-48;
		else if(c=='B')c+=a[i]-47;
		else if(c=='C')c+=a[i]-46;
		else if(c=='D')c+=a[i]-51;
		else if(c=='E')c+=a[i]-50;
		else c+=a[i]-49;
	}
	if(c=='A')printf("yes");
	else printf("no");
	return 0;
}