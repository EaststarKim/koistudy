#include <stdio.h>
int main()
{
	int i,n,x,y,a,b;
	a=b=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",&x,&y);
		if(x>y)a+=x+y;
		else if(x<y)b+=x+y;
		else a+=x,b+=y;
	}
	printf("%d %d",a,b);
	return 0;
}