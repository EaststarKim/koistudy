#include <stdio.h>
int a[1010], b[1010];
int main()
{
	int i,lp,rp,p,n,h;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	p=1;
	b[p]=a[1];
	for(i=2;i<=n;++i)
	{
		if(b[p]>a[i]) b[++p]=a[i];
		else
		{
			lp=1;
			rp=p;
			while(lp<=rp)
			{
				h=(lp+rp)/2;
				if(lp==rp)
				{
					if(b[h]<a[i])
					{
						b[h]=a[i];
						break;
					}
				}
				if(b[h]==a[i]) break;
				if(b[h]<a[i]) rp=h;
				else if(b[h]>a[i]) lp=h+1;
			}
		}
	}
	printf("%d\n",p);
	return 0;
}