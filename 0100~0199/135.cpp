#include <stdio.h>

int a[110][110];

int main()
{
	int i, j, r, c, p, cnt, sw;
	int n;
	scanf("%d",&n);
	sw=r=cnt=1;
	p=n;
	c=0;
	while(p>=1)
	{
		for(i=1;i<=p;++i)c+=sw, a[r][c]=cnt++;
		--p;
		for(i=1;i<=p;++i)r+=sw, a[r][c]=cnt++;
		sw=-sw;
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j) printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}