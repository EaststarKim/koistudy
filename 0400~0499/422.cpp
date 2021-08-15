#include <stdio.h>
int d[101],n;
__int64 dy[21][101],p,m;
int main()
{
	int i,j,t;
	scanf("%d",&n);
	for(i=0;i<n;++i)scanf("%d",&d[i]);
	dy[d[0]][0]=1;
	for(i=1;i<n-1;++i)
	{
		for(j=0;j<21;++j)
		{
			p=m=0;
			t=j-d[i];
			if(0<=t&&t<=20)p=dy[t][i-1];
			t=j+d[i];
			if(0<=t&&t<=20)m=dy[t][i-1];
			dy[j][i]=p+m;
		}
	}
	printf("%I64d",dy[d[n-1]][n-2]);
	return 0;
}