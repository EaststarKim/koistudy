#include <stdio.h>
int gcd(int x,int y)
{
	if(x%y==0)return y;
	x%=y;
	return gcd(y,x);
}
int main()
{
	int i,n,a,b,c,d,t;
	scanf("%d",&n);
	scanf("%d%d",&a,&b);
	for(i=1;i<n;++i)
	{
		scanf("%d%d",&c,&d);
		a=a*d+c*b;
		b*=d;
		t=gcd(a,b);
		if(t<0)t=-t;
		a/=t;
		b/=t;
	}
	if(!a)printf("0");
	else printf("%d/%d",a,b);
	return 0;
}