#include <stdio.h>
int a[8]={0,1,3,9,27,81,243,729},m[8],p[8],n,c1,c2,sw;
void back(int k,int s)
{
	int i;
	if(s==n)
	{
		printf("%d ",n);
		for(i=1;i<=c1;++i)printf("%d ",m[i]);
		printf("0 ");
		for(i=1;i<=c2;++i)printf("%d ",p[i]);
		sw=1;
		return;
	}
	if(k>7)return;
	m[++c1]=a[k];
	back(k+1,s-a[k]);
	--c1;
	if(sw)return;
	p[++c2]=a[k];
	back(k+1,s+a[k]);
	--c2;
	if(sw)return;
	back(k+1,s);
}
int main()
{
	scanf("%d",&n);
	back(1,0);
	return 0;
}