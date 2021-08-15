#include <stdio.h>
#define max(a,b) a>b? a:b
int a[101],b[4][101];
int main()
{
	int i,n,m;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	b[2][1]=b[3][1]=a[1];
	for(i=2;i<=n;++i)
	{
		b[0][i]=max(b[0][i-1],b[1][i-1]);
		b[1][i]=max(b[2][i-1],b[3][i-1]);
		b[2][i]=max(b[0][i-1],b[1][i-1]);
		b[2][i]+=a[i];
		b[3][i]=b[2][i-1]+a[i];
	}
	m=max(b[1][n],b[2][n]);
	printf("%d",max(m,b[3][n]));
	return 0;
}
