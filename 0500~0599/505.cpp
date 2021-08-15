#include <stdio.h>
#define INF 20000000
int a[205][105][105];
int n,m;
char map[101][101];
int main()
{
	int i,j,k,n,m;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)scanf("%s",map[i]);
	if(map[0][0]=='1')a[0][0][0]=1;
	for(i=1;i<=n+m-2;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(!(j<m&&i-j<n))continue;
			for(k=0;k<=i;k++)
			{
				if(!(k<m&&i-k<n)) continue;
				int plus=0,max=-INF;
				if(map[j][i-j]=='2'||map[k][i-k]=='2')
				{
					a[i][j][k]=-INF;
					continue;
				}
				if(map[j][i-j]=='1')plus++;
				if(map[k][i-k]=='1')plus++;
				if(j==k&&plus==2)plus--;
				if(i!=0&&max<a[i-1][j][k])max=a[i-1][j][k];
				if(i!=0&&j!=0&&max<a[i-1][j-1][k])max=a[i-1][j-1][k];
				if(i!=0&&k!=0&&max<a[i-1][j][k-1])max=a[i-1][j][k-1];
				if(i!=0&&j!=0&&k!=0&&max<a[i-1][j-1][k-1])max=a[i-1][j-1][k-1];
				if(max==-INF)a[i][j][k]=-INF;
				else a[i][j][k]=max+plus;
			}
		}
	}
	printf("%d",a[n+m-2][m-1][m-1]);
	return 0;
}