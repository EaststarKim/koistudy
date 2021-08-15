#include <stdio.h>
#define max(x,y) x<y? y:x
int a[10000010],b;
int back(int lind, int rind)
{
	int lmax=a[lind],rmax=a[rind];
	while(lind<rind)
	{
		if(lind%2==0&&rind%2) lind>>=1,rind>>=1;
		else lind+=lind%2, rind-=!(rind%2);
		lmax=max(lmax,a[lind]);
		rmax=max(rmax,a[rind]);
	}
	return max(lmax,rmax);
}
int main()
{
	int i,n,q,l,r;
	scanf("%d%d",&n,&q);
	b=1;
	while(b<n)b<<=1;
	for(i=0;i<n;++i)scanf("%d",&a[i+b]);
	for(i=b-1;i>0;--i)a[i]=max(a[i*2],a[i*2+1]);
	for(i=1;i<=q;++i)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",back(l+b-1,r+b-1));
	}
	return 0;
}