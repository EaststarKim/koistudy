#include <stdio.h>
int a[100010],m;
int main()
{
	int i,n,g,t,tm,p,q;
	scanf("%d%d%d%d%d%d",&n,&g,&t,&tm,&p,&q);
	for(i=0;i<n;++i)scanf("%d",&a[i]);
	for(i=0;i<t;++i)
	{
		if(a[i%n])m+=p;
		else if(i%tm==0)m+=p;
		else m+=q;
		if(g<=m)break;
	}
	if(i==t)printf("Dirty Dormitory!");
	else printf("%d",i+1);
	return 0;
}