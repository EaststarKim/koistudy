#include <stdio.h>
#include <string.h>
char a[10],c;
int main()
{
	int i,n,sw=0;
	scanf("%s",a);
	n=strlen(a)-1;
	for(i=0;i<=n/2;++i)c=a[i],a[i]=a[n-i],a[n-i]=c;
	for(i=0;i<=n;++i)
	{
		if(sw==1 || a[i]!='A')sw=1;
		if(sw)
		{
			if(a[i]>64 && a[i]<97)printf("%d",a[i]-65);
			else printf("%d",a[i]-92);
		}
	}
	return 0;
}