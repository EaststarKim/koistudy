#include <stdio.h>
int main()
{
	int a,b,c,d,w,x,y,z;
	scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&w,&x,&y,&z);
	if(w<c&&x<d&&y>a&&z>b)printf("rectangle");
	else if((y==a&&z==b)||(w==c&&z==b)||(y==a&&x==d)||(w==c&&x==d))printf("point");
	else if(y<a||z<b||x>d||w>c)printf("none");
	else printf("line");
	return 0;
}