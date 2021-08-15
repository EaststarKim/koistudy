#include <stdio.h>
#include <algorithm>
int a[1000010],rm[1000010],index[1000010],f,r;
int main()
{
	int i,n,k,ans=2100000010,s;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;++i)scanf("%d",&a[i]);
	std::sort(a,a+n);
	rm[r]=a[1]-a[0],index[r++]=1;
	for(i=2;i<n-k-1;++i)
	{
		while(r>f)
		{
			if(rm[r-1]<a[i]-a[i-1])break;
			--r;
		}
		rm[r]=a[i]-a[i-1],index[r++]=i;
	}
	for(i=0;i<=k;++i)
	{
		while(r>f)
		{
			if(rm[r-1]<a[n+i-k-1]-a[n+i-k-2])break;
			--r;
		}
		rm[r]=a[n+i-k-1]-a[n+i-k-2],index[r++]=n+i-k-1;
		if(index[f]<i)++f;
		s=rm[f]+a[n+i-k-1]-a[i];
		if(ans>s)ans=s;
	}
	printf("%d",ans);
	return 0;
}
