#include <stdio.h>
int a[7],mx;
int main()
{
	int i,k;
	for(i=1;i<4;++i)scanf("%d",&k),++a[k];
	for(i=1;i<7;++i)
	{
		if(a[i]==3)
		{
			printf("%d",(10+i)*1000);
			break;
		}
		if(a[i]==2)
		{
			printf("%d",(10+i)*100);
			break;
		}
		if(a[i]==1 && mx<i)mx=i;
	}
	if(i==7)printf("%d",mx*100);
	return 0;
}