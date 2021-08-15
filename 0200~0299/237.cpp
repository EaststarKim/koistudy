#include <stdio.h>
int a[4][4];
int main()
{
	int i,x,b,c,d,e,f;
	for(i=1;i<4;++i)
	{
		scanf("%d%d%d%d%d%d",&x,&b,&c,&d,&e,&f);
		f-=c;
		if(f<0)--e,f+=60;
		e-=b;
		if(e<0)--d,e+=60;
		d-=x;
		a[i][1]=d;
		a[i][2]=e;
		a[i][3]=f;
	}
	for(i=1;i<4;++i)printf("%d %d %d\n",a[i][1],a[i][2],a[i][3]);
	return 0;
}