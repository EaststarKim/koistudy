#include <stdio.h>
int main()
{
	int a1,a2,b1,b2,t;
	scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
	if(a1>a2)t=a1,a1=a2,a2=t;
	if(b1>b2)t=b1,b1=b2,b2=t;
	if(b1<a1&&a1<b2&&((b2<a2&&a2<100+b1)||(b2<100+a2&&a2<b1))) printf("cross\n");
	else if(b1<a2&&a2<b2&&((b2<a1&&a1<100+b1)||(b2<100+a1&&a1<b1))) printf("cross\n");
	else printf("not cross\n");
	return 0;
}
