#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
int a[1000],p;
char c[1000010];
int main()
{
	int i,j,k,n,t;
	scanf("%s",c);
	n=strlen(c);
	t=sqrt(n);
	for(i=1;i<=t;++i)
	{
		if(n%i==0)a[++p]=i,a[++p]=n/i;
	}
	std::sort(&a[1],&a[p+1]);
	for(i=1;i<=p;++i)
	{
		t=a[i];
		for(j=t;j<=n-t;j+=t)
		{
			for(k=0;k<t;++k)
			{
				if(c[k]!=c[j+k])break;
			}
			if(k<t)break;
		}
		if(j>n-t)break;
	}
	printf("%d",t);
	return 0;
}