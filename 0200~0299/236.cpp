#include <stdio.h>
#include <algorithm>
using namespace std;
int a[9],b[5],s,cnt;
void back(int c,int p,int k)
{
	int i;
	if(c==5)
	{
		if(s==k)
		{
			for(i=1;i<5;++i)printf("%d ",b[i]);
			printf("\n");
			++cnt;
		}
		return;
	}
	for(i=p;i>0;--i)
	{
		if(k+a[i]<=s)
		{
			b[c]=a[i];
			back(c+1,i,k+a[i]);
		}
	}
}
int main()
{
	int i;
	for(i=1;i<9;++i)scanf("%d",&a[i]);
	scanf("%d",&s);
	sort(&a[1],&a[9]);
	back(1,8,0);
	printf("%d",cnt);
	return 0;
}