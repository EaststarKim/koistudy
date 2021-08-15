#include <stdio.h>
#include <string.h>
char a[21];
int b[10];
int main()
{
	int i,n,k;
	__int64 s=0,x=0;
	scanf("%s",a);
	n=strlen(a);
	for(i=0;i<n;++i)
	{
		if(a[i]<48)break;
		s=s*10+a[i]-48;
	}
	k=i;
	++i;
	for(;i<=n;++i)
	{
		if(a[i]>47)x=x*10+a[i]-48;
		else if(a[k]<45)s+=x,x=0,k=i;
		else s-=x,x=0,k=i;
	}
	printf("%I64d",s);
	return 0;
}