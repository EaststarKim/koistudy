#include <stdio.h>
#include <string.h>
int a[110][110],b[110][110],chk[110][110],mx=1,sm=101,em,n;
int dr[]={-1,0,1,0},dc[]={0,1,0,-1};
void back(int r,int c)
{
	int i,nr,nc;
	for(i=0;i<4;++i)
	{
		nr=r+dr[i];
		nc=c+dc[i];
		if(b[nr][nc]||chk[nr][nc]||nr<1||nr>n||nc<1||nc>n)continue;
		chk[nr][nc]=1;
		back(nr,nc);
	}
}
int main()
{
	int i,j,k,l,cnt;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			scanf("%d",&a[i][j]);
			if(sm>a[i][j])sm=a[i][j];
			if(em<a[i][j])em=a[i][j];
		}
	}
	for(i=sm;i<em;++i)
	{
		cnt=0;
		for(k=1;k<=n;++k)
		{
			for(l=1;l<=n;++l)
			{
				if(a[k][l]<=i)b[k][l]=1;
			}
		}
		for(k=1;k<=n;++k)
		{
			for(l=1;l<=n;++l)
			{
				if(b[k][l]==0&&chk[k][l]==0)
				{
					++cnt;
					chk[k][l]=1;
					back(k,l);
				}
			}
		}
		if(mx<cnt)mx=cnt;
		memset(chk,0,sizeof(chk));
	}
	printf("%d",mx);
	return 0;
}
