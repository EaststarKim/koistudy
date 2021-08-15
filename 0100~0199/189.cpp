#include <stdio.h>
char a[110][110];
int b[110][110],q[2][10010],f,r=1;
int main()
{
	int i,j,h,w,er,ec,ro,co;
	scanf("%d%d",&h,&w);
	for(i=1;i<=h;++i)scanf("%s",a[i]+1);
	for(i=1;i<=h;++i)
	{
		for(j=1;j<=w;++j)
		{
			b[i][j]=10001;
			if(a[i][j]=='S')b[i][j]=0,q[0][1]=i,q[1][1]=j;
			if(a[i][j]=='G')er=i,ec=j;
		}
	}
	while(f<r)
	{
		ro=q[0][++f];
		co=q[1][f];
		if(ro==er&&co==ec)break;
		if(ro>1&&a[ro-1][co]!='#'&&b[ro][co]+1<b[ro-1][co])
		{
			q[0][++r]=ro-1;
			q[1][r]=co;
			b[ro-1][co]=b[ro][co]+1;
		}
		if(co>1&&a[ro][co-1]!='#'&&b[ro][co]+1<b[ro][co-1])
		{
			q[0][++r]=ro;
			q[1][r]=co-1;
			b[ro][co-1]=b[ro][co]+1;
		}
		if(ro<h&&a[ro+1][co]!='#'&&b[ro][co]+1<b[ro+1][co])
		{
			q[0][++r]=ro+1;
			q[1][r]=co;
			b[ro+1][co]=b[ro][co]+1;
		}
		if(co<w&&a[ro][co+1]!='#'&&b[ro][co]+1<b[ro][co+1])
		{
			q[0][++r]=ro;
			q[1][r]=co+1;
			b[ro][co+1]=b[ro][co]+1;
		}
	}
	if(ro==er&&co==ec)printf("%d",b[ro][co]);
	else printf("-1");
	return 0;
}