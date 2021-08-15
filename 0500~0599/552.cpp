#include <stdio.h>
int n,k,cnt;
void back(int p,int g,int s)
{
	if(p>n)
	{
		if(s==k)++cnt;
		return;
	}
	back(p+1,g,s+1);
	back(p+1,!g,s);
}
int main()
{
	scanf("%d%d",&n,&k);
	back(2,0,0);
	printf("%d",cnt*2);
	return 0;
}