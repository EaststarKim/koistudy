#include <stdio.h>
int a[300010],d[300010],s,l;
long long t;
int main()
{
	int i,j,n,p;
	scanf("%d%d",&n,&p);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	d[0]=t=1;
	for(i=1;i<=n;++i)
	{
		s+=a[i];
		while(s>p)
		{
			t-=d[l];
			s-=a[++l];
		}
		d[i]=t%3141592;
		t+=d[i];
	}
	printf("%d",d[n]);
	return 0;
}
