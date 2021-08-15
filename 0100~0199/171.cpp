#include <stdio.h>
int a[110][110],chk[110],q[210],f,r=1;
int main()
{
	int i,n,m,x,y,p;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		++a[x][0];
		++a[y][0];
		a[x][a[x][0]]=y;
		a[y][a[y][0]]=x;
	}
	q[1]=chk[1]=1;
	while(f<r)
	{
		p=q[++f];
		for(i=1;i<=a[p][0];++i)
		{
			if(chk[a[p][i]]==0)q[++r]=a[p][i],chk[a[p][i]]=1;
		}
	}
	for(i=1;i<=f;++i)printf("%d ",q[i]);
	return 0;
}