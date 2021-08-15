#include <stdio.h>
#include <math.h>
int a[]={1,2,4,2},n;
void back(int s,int p)
{
	int i,j,m;
	if(p>n)
	{
		printf("%d\n",s);
		return;
	}
	s*=10;
	for(i=0;i<4;++i)
	{
		s+=a[i];
		m=(int)sqrt(s);
		for(j=3;j<=m;++j)
		{
			if(!(s%j))break;
		}
		if(j>m)back(s,p+1);
	}
}
int main()
{
	scanf("%d",&n);
	back(2,2);
	back(3,2);
	back(5,2);
	back(7,2);
	return 0;
}