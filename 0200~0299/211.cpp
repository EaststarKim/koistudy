#include <stdio.h>
int a[21], b[21];
int main()
{
	int i,acnt=0,bcnt=1;
	for(i=1;i<=20;++i)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	b[1]=!b[1];
	b[2]=!b[2];
	for(i=2;i<=20;++i)
	{
		if(a[i-1])
		{
			a[i-1]=!a[i-1];
			a[i]=!a[i];
			a[i+1]=!a[i+1];
			++acnt;
		}
		if(b[i-1])
		{
			b[i-1]=!b[i-1];
			b[i]=!b[i];
			b[i+1]=!b[i+1];
			++bcnt;
		}
	}
	if(a[20]==1)printf("%d",bcnt);
	else if(b[20]==1)printf("%d",acnt);
	else
	{
		if(acnt<bcnt)printf("%d",acnt);
		else printf("%d",bcnt);
	}
	return 0;
}