#include <stdio.h>
#include <string.h>
char a[7];
int main()
{
	int i,n,sw,s;
	scanf("%s",a);
	n=strlen(a)-1;
	s=sw=0;
	for(i=n;i>=0;--i)
	{
		if(a[i]==48&&sw)printf("0");
		if(a[i]>48)printf("%d",a[i]-48),s+=a[i]-48,sw=1;
	}
	printf("\n%d",s);
	return 0;
}