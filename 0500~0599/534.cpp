#include <stdio.h>
int a[6]={0,5,3,2,4};
char c[5];
int main()
{
	int i,j,n,t=1,b=6,s=1,p,k;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%s",c);
		p=0;
		if(c[0]=='N')p=1;
		if(c[0]=='E')p=2;
		if(c[0]=='S')p=3;
		if(c[0]=='W')p=4;
		if(c[0]=='R')
		{
			for(j=4;j>0;--j)a[j+1]=a[j];
			a[1]=a[5];
			a[5]=0;
		}
		if(c[0]=='L')
		{
			for(j=1;j<5;++j)a[j-1]=a[j];
			a[4]=a[0];
			a[0]=0;
		}
		if(p&&p<3)k=t,t=a[p+2],a[p+2]=b,b=a[p],a[p]=k;
		if(p&&p>2)k=t,t=a[(p+2)%4],a[(p+2)%4]=b,b=a[p],a[p]=k;
		s+=t;
	}
	printf("%d",s);
	return 0;
}