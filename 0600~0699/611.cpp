#include <stdio.h>
double s[1010],c[1010];
int main()
{
	int i,n,k;
	double m,l,sm=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%lf%lf",&s[i],&c[i]);
	for(i=1;i<=n;++i)
	{
		m=s[i]/c[i]*100;
		if(m>=85)printf("A"),k=95,l=4.3;
		else if(m>=70)printf("B"),k=80,l=3.3;
		else if(m>=55)printf("C"),k=65,l=2.3;
		else if(m>=40)printf("D"),k=50,l=1.3;
		else printf("F "),k=0,l=0;
		if(k)
		{
			if(m>=k)printf("+ ");
			else if(m>=k-5)printf("0 "),l-=0.3;
			else printf("- "),l-=0.6;
		}
		printf("%.1lf\n",l);
		sm+=l;
	}
	printf("%.2lf\n",sm/n);
	return 0;
}