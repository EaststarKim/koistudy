#include <stdio.h>
int a[11],chk[10],k,sw;
char c[10];
void max(int p)
{
	int i;
	if(p==k)
	{
		for(i=1;i<=k+1;++i)printf("%d",a[i]);
		printf("\n");
		sw=1;
		return;
	}
	for(i=9;i>=0;--i)
	{
		if(sw)return;
		if(c[p]=='>'&&a[p+1]>i&&!chk[i])
		{
			chk[i]=1;
			a[p+2]=i;
			max(p+1);
			chk[i]=0;
		}
		if(c[p]=='<'&&a[p+1]<i&&!chk[i])
		{
			chk[i]=1;
			a[p+2]=i;
			max(p+1);
			chk[i]=0;
		}
	}
}
void min(int p)
{
	int i;
	if(p==k)
	{
		for(i=1;i<=k+1;++i)printf("%d",a[i]);
		sw=1;
		return;
	}
	for(i=0;i<10;++i)
	{
		if(sw)return;
		if(c[p]=='>'&&a[p+1]>i&&!chk[i])
		{
			chk[i]=1;
			a[p+2]=i;
			min(p+1);
			chk[i]=0;
		}
		if(c[p]=='<'&&a[p+1]<i&&!chk[i])
		{
			chk[i]=1;
			a[p+2]=i;
			min(p+1);
			chk[i]=0;
		}
	}
}
int main()
{
	int i;
	scanf("%d",&k);
	for(i=0;i<k;++i)scanf(" %c",&c[i]);
	for(i=9;i>=0;--i)
	{
		a[1]=i;
		chk[i]=1;
		max(0);
		chk[i]=0;
		if(sw)break;
	}
	sw=0;
	for(i=0;i<10;++i)
	{
		a[1]=i;
		chk[i]=1;
		min(0);
		chk[i]=0;
		if(sw)break;
	}
	return 0;
}