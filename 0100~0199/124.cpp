#include <stdio.h>

int main()
{
	int x, y, z, a, b, c, s;
	scanf("%d %d %d",&x, &y, &z);
	if(y>=11) a=x+1, b=y+2-12;
	else a=x, b=y+2;
	s=0;
	if(y%2 && y<=7) s+=31;
	else if(y%2==0 && y>=8) s+=31;
	else if(y==2)
	{
		if((x%400==0)||(x%4==0 && x%100)) s+=29;
		else s+=28;
	}
	else s+=30;
	++y;
	if(y>12) y-=12, ++x;
	if(y%2 && y<=7) s+=31;
	else if(y%2==0 && y>=8) s+=31;
	else if(y==2)
	{
		if((x%400==0)||(x%4==0 && x%100)) s+=29;
		else s+=28;
	}
	else s+=30;
	s%=7;
	if(z<s-1) c=z+7-s;
	else c=z-s;
	printf("%d %d %d\n",a, b, c);
	return 0;
}