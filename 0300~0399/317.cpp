#include <stdio.h>
#include <algorithm>
#define min(i,j) i<j? i:j
int a[3][101],s;
int main()
{
	int i,n,m,k,d,c;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=k;++i)scanf("%d%d",&a[1][i],&a[2][i]);
	scanf("%d%d",&d,&c);
	for(i=1;i<=k;++i)
	{
		if(a[1][i]==d)s+=abs(a[2][i]-c);
		else if(d==1)
		{
			if(a[1][i]==3)s+=c+a[2][i];
			else if(a[1][i]==4)s+=n-c+a[2][i];
			else s+=min(c+m+a[2][i],n-c+m+n-a[2][i]);
		}
		else if(d==2)
		{
			if(a[1][i]==3)s+=c+m-a[2][i];
			else if(a[1][i]==4)s+=n-c+m-a[2][i];
			else s+=min(c+m+a[2][i],n-c+m+n-a[2][i]);
		}
		else if(d==3)
		{
			if(a[1][i]==1)s+=c+a[2][i];
			else if(a[1][i]==2)s+=m-c+a[2][i];
			else s+=min(c+n+a[2][i],n-c+n+m-a[2][i]);
		}
		else
		{
			if(a[1][i]==1)s+=c+n-a[2][i];
			else if(a[1][i]==2)s+=m-c+n-a[2][i];
			else s+=min(c+n+a[2][i],n-c+n+m-a[2][i]);
		}
	}
	printf("%d",s);
	return 0;
}