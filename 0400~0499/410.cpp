#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1001];
int main()
{
	int i,n,x,y,z;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(x==y&&y==z)a[i]=10000+x*1000;
		else
		{
			if(x==y||x==z)a[i]=1000+x*100;
			else if(y==z)a[i]=1000+y*100;
			else
			{
				if(x>y&&x>z)a[i]=x*100;
				if(y>x&&y>z)a[i]=y*100;
				else a[i]=z*100;
			}
		}
	}
	sort(&a[1],&a[n+1]);
	printf("%d",a[n]);
	return 0;
}