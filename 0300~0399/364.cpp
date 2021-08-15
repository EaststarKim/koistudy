#include <stdio.h>
int a[7],mx2;
int main()
{
	int i,j,n,mx1,t,s,k,l;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		mx1=t=s=0;		
		for(j=1;j<5;++j)scanf("%d",&k),++a[k];
		for(j=1;j<7;++j)
		{
			if(a[j]==4)
			{
				s=(10+j)*5000;
				break;
			}
			if(a[j]==3)
			{
				s=(10+j)*1000;
				break;
			}
			if(a[j]==2)
			{
				if(t)l=j;
				else k=j;
				++t;
			}
			if(a[j]==1 && mx1<j)mx1=j;
		}
		for(j=1;j<7;++j)a[j]=0;
		if(t==2)s=(4+k+l)*500;
		if(t==1)s=(10+k)*100;
		if(!s)s=mx1*100;
		if(mx2<s)mx2=s;
	}
	printf("%d",mx2);
	return 0;
}