#include <stdio.h>
int a[2010][4],b[110];
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
	for(i=1;i<4;++i)
	{
		for(j=1;j<=n;++j)
		{
			if(b[a[j][i]])b[a[j][i]]=-1;
			else b[a[j][i]]=j;
		}
		for(j=1;j<101;++j)
		{
			if(b[j]>0)a[b[j]][0]+=j;
			b[j]=0;
		}
	}
	for(i=1;i<=n;++i)printf("%d\n",a[i][0]);
	return 0;
}