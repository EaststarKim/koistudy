#include <stdio.h>
int a[21],n,k,sw;
void back(int p,int s)
{
	if(p>n)
	{
		if(s==k)sw=1;
		return;
	}
	if(s+a[p]<=k)back(p+1,s+a[p]);
	if(sw)return;
	back(p+1,s);
}
int main()
{
	int i;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	back(1,0);
	if(sw)printf("YES");
	else printf("NO");
	return 0;
}