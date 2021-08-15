#include <stdio.h>
int a[70][70], wcnt, bcnt;
void back(int r, int c, int k)
{
	int i, j, sw;
	sw=a[r][c];
	for(i=0;i<k;++i)
	{
		for(j=0;j<k;++j)if(a[r+i][c+j]!=sw)break;
		if(j<k)break;
	}
	if(i<k)
	{
		back(r,c,k/2);
		back(r+k/2,c,k/2);
		back(r,c+k/2,k/2);
		back(r+k/2,c+k/2,k/2);
	}
	else if(sw==0)++wcnt;
	else ++bcnt;
	return;
}
int main()
{
	int i, j, n;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)scanf("%1d",&a[i][j]);
	}
	back(1,1,n);
	printf("%d\n%d",wcnt,bcnt);
	return 0;
}