#include <stdio.h>
int a[10],s;
int main()
{
	int i,n,k;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&k);
		++a[k];
	}
	s+=a[4];
	s+=a[3];
	if(a[1]<a[3])a[1]=0;
	else a[1]-=a[3];
	s+=a[2]/2;
	a[2]%=2;
	if(a[2])
	{
		if(a[1]<2)a[1]=0;
		else a[1]-=2;
		++s;
	}
	s+=a[1]/4;
	a[1]%=4;
	if(a[1])++s;
	printf("%d",s);
	return 0;
}