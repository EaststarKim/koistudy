#include <stdio.h>
int a[10000010],mx;
int main()
{
	int i,n,m;
	__int64 k;
	scanf("%d%d",&n,&m);
	if(n>m)n-=m,m+=n,n=m-n;
	for(i=n;i<=m;++i)
	{
		k=i;
		while(k>1)
		{
			if(k%2)k=k*3+1;
			else k/=2;
			++a[i];
			if(k<i&&a[k])
			{
				a[i]+=a[k];
				break;
			}
		}
		if(mx<a[i])mx=a[i];
	}
	printf("%d",mx+1);
	return 0;
}
