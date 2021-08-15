#include <stdio.h>
int f,r=1;
int chk[9][9],x[]={-2,-1,1,2,2,1,-1,-2},y[]={1,2,2,1,-1,-2,-2,-1};
struct data
{
	int x,y,l;
}q[70];
int main()
{
	int i,rr,cc,s,k,nr,nc;
	scanf("%d%d%d%d",&rr,&cc,&s,&k);
	q[1].l=0;
	q[1].x=rr;
	q[1].y=cc;
	while(f<r)
	{
	    data d=q[++f];
		if(d.x==s&&d.y==k)
		{
			printf("%d",q[f].l);
			return 0;
		}
		for(i=0;i<8;++i)
		{
			nr=d.x+x[i];
			nc=d.y+y[i];
			if(nr<1||nc<1||nr>8||nc>8||chk[nr][nc])continue;
			chk[nr][nc]=1;
			q[++r].x=nr;
			q[r].y=nc;
			q[r].l=q[f].l+1;
		}
	}
}
