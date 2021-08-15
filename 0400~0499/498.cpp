#include <stdio.h>
int x[100001],mx,mi,r,l,rx,lx;
int main()
{
    int m,n,i;
    scanf("%d%d",&n,&m);
	rx=m;
    for(i=1;i<=n;i++)
    {
        scanf("%d",x+i);
        if(x[i]>0)
        {
			if(rx>x[i])rx=x[i],r=i;
        }
        else
		{
			if(lx<-x[i])lx=-x[i],l=i;
		}
	}
    mx=m-rx;
	if(rx<lx)mi=l;
	else mi=r;
    if(mx<lx)
	{
		mx=lx;
		if(rx<lx)mi=r;
		else mi=l;
	}
	printf("%d %d",mi,mx);
    return 0;
}