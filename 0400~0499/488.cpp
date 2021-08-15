#include <stdio.h>
int a[100010],b[100010],c[100010],acnt,bcnt=1;
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%1d",&a[i]),b[i]=a[i];
	for(i=1;i<=n;++i)scanf("%1d",&c[i]);
	b[1]=!b[1];
	b[2]=!b[2];
	for(i=2;i<=n;++i)
	{
		if(a[i-1]!=c[i-1])
		{
			a[i-1]=!a[i-1];
			a[i]=!a[i];
			a[i+1]=!a[i+1];
			++acnt;
		}
		if(b[i-1]!=c[i-1])
		{
			b[i-1]=!b[i-1];
			b[i]=!b[i];
			b[i+1]=!b[i+1];
			++bcnt;
		}
	}
	if(a[n]!=c[n])acnt=-1;
	if(b[n]!=c[n])bcnt=-1;
	if(acnt<0&&bcnt<0)printf("-1");
	else if(bcnt<0||(acnt>=0&&acnt<bcnt))printf("%d",acnt);
	else printf("%d",bcnt);
	return 0;
}