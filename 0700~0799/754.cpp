#include <stdio.h>
int a[110][110],chk[110][110]={{1}},n,m,s;
int dr[]={-1,0,1,1,0,-1},dc[]={0,1,0,0,-1,0};
void back(int r,int c)
{
	int i,nr,nc;
	for(i=0;i<6;++i)
	{
		dc[0]=dc[2]=r%2;
		dc[3]=dc[5]=r%2-1;
		nr=r+dr[i];
		nc=c+dc[i];
		if(nr<0||nr>n+1||nc<0||nc>m+1||chk[nr][nc]||a[nr][nc])continue;
		chk[nr][nc]=1;
		back(nr,nc);
	}
}
int main()
{
	int i,j,k,ni,nj;
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)scanf("%d",&a[i][j]);
	}
	back(0,0);
	for(i=1;i<=n;++i)
	{
		dc[0]=dc[2]=i%2;
		dc[3]=dc[5]=i%2-1;
		for(j=1;j<=m;++j)
		{
			if(a[i][j])
			{
				s+=6;
				for(k=0;k<6;++k)
				{
					ni=i+dr[k];
					nj=j+dc[k];
					if(ni<1||ni>n||nj<1||nj>m)continue;
					if(a[ni][nj])--s;
					else if(!chk[ni][nj])--s;
				}
			}
		}
	}
	printf("%d",s);
	return 0;
}