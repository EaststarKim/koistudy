#include <stdio.h>
int a[4],b[4],c[4];
int main()
{
	int i,n,k;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&k);
		a[0]+=k;
		if(k==1)++a[1];
		if(k==2)++a[2];
		else ++a[3];
		scanf("%d",&k);
		b[0]+=k;
		if(k==1)++b[1];
		if(k==2)++b[2];
		else ++b[3];
		scanf("%d",&k);
		c[0]+=k;
		if(k==1)++c[1];
		if(k==2)++c[2];
		else ++c[3];
	}
	if(a[0]>b[0]&&a[0]>c[0])printf("1 %d",a[0]);
	if(a[0]<b[0]&&b[0]>c[0])printf("2 %d",b[0]);
	if(c[0]>b[0]&&a[0]<c[0])printf("3 %d",c[0]);
	if(a[0]==b[0]&&a[0]>c[0])
	{
		if(a[3]>b[3])printf("1 ");
		else if(a[3]<b[3])printf("2 ");
		else
		{
			if(a[2]>b[2])printf("1 ");
			else if(a[2]<b[2])printf("2 ");
			else printf("0 ");
		}
		printf("%d",a[0]);
	}
	if(a[0]==c[0]&&a[0]>b[0])
	{
		if(a[3]>c[3])printf("1 ");
		else if(a[3]<c[3])printf("3 ");
		else
		{
			if(a[2]>c[2])printf("1 ");
			else if(a[2]<c[2])printf("3 ");
			else printf("0 ");
		}
		printf("%d",a[0]);
	}
	if(b[0]==c[0]&&a[0]<b[0])
	{
		if(b[3]>c[3])printf("2 ");
		else if(b[3]<c[3])printf("3 ");
		else
		{
			if(b[2]>c[2])printf("2 ");
			else if(b[2]<c[2])printf("3 ");
			else printf("0 ");
		}
		printf("%d",b[0]);
	}
	if(a[0]==b[0]&&a[0]==c[0])
	{
		if(a[3]>b[3]&&a[3]>c[3])printf("1 ");
		else if(a[3]<b[3]&&b[3]>c[3])printf("2 ");
		else if(c[3]>b[3]&&a[3]<c[3])printf("3 ");
		else
		{
			if(a[2]>b[2]&&a[2]>c[2])printf("1 ");
			else if(a[2]<b[2]&&b[2]>c[2])printf("2 ");
			else if(c[2]>b[2]&&a[2]<c[2])printf("3 ");
			else printf("0 ");
		}
		printf("%d",a[0]);
	}
	return 0;
}