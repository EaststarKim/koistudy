#include <stdio.h>
#include <math.h>
int a[110];
int f(int n)
{
	if(!n)return 0;
	int k=(int)log10(n);
	k=(int)pow(10,k);
	return f(n/10)+(n%10)*k;
}
int main()
{
	int i,n,s,t;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<=n;++i)
	{
		s=a[i]+f(a[i]);
		t=f(s);
		if(s==t)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}