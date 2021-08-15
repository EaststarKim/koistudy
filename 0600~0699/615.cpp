#include <stdio.h>
int main()
{
	int i,a,b,c,d,w,x,y,z;
	for(i=1;i<5;++i)
	{
		scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&w,&x,&y,&z);
		if(w<c&&x<d&&y>a&&z>b)printf("a\n");
		else if((y==a&&z==b)||(w==c&&z==b)||(y==a&&x==d)||(w==c&&x==d))printf("c\n");
		else if(y<a||z<b||x>d||w>c)printf("d\n");
		else printf("b\n");
	}
	return 0;
}