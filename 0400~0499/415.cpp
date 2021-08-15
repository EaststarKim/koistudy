#include <stdio.h>
int a[2][6],mr,mc,x,y;
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<6;++i)scanf("%d%d",&a[0][i],&a[1][i]);
	for(i=0;i<6;++i)
	{
		if(a[0][i]<3&&mr<a[1][i])mr=a[1][i];
		if(a[0][i]>2&&mc<a[1][i])mc=a[1][i];
		if((a[0][i]<2&&a[0][(i+1)%6]==3)||(a[0][i]>3&&a[0][(i+1)%6]<2)||(a[0][i]==2&&a[0][(i+1)%6]>3)||(a[0][i]==3&&a[0][(i+1)%6]==2))x=a[1][i],y=a[1][(i+1)%6];
	}
	printf("%d",(mr*mc-x*y)*n);
	return 0;
}