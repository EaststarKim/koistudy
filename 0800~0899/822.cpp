#include <stdio.h>
struct data
{
	int x,y,z,lev;
}q[1000010];
int a[110][110][110],f,r,cnt;
int dx[]={-1,0,0,0,0,1},dy[]={0,-1,0,1,0,0},dz[]={0,0,1,0,-1,0};
int main()
{
	int i,j,k,m,n,h,nx,ny,nz;
	scanf("%d%d%d",&m,&n,&h);
	for(i=h;i>0;--i)
	{
		for(j=1;j<=n;++j)
		{
			for(k=1;k<=m;++k)
			{
				scanf("%d",&a[i][j][k]);
				if(a[i][j][k]==1)q[++r].x=i,q[r].y=j,q[r].z=k;
				if(!a[i][j][k])++cnt;
			}
		}
	}
	while(f<r)
	{
		++f;
		for(i=0;i<6;++i)
		{
			nx=q[f].x+dx[i];
			ny=q[f].y+dy[i];
			nz=q[f].z+dz[i];
			if(nx<1||nx>h||ny<1||ny>n||nz<1||nz>m||a[nx][ny][nz])continue;
			q[++r].x=nx,q[r].y=ny,q[r].z=nz,q[r].lev=q[f].lev+1;
			a[nx][ny][nz]=1;
			--cnt;
			if(!cnt)break;
		}
	}
	if(cnt)printf("-1");
	else printf("%d",q[r].lev);
	return 0;
}
