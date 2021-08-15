#include <stdio.h>

int a[10][5];

int main()
{
	int n, i, j, cnt;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=4;++j) scanf("%d",&a[i][j]);
	}
	cnt=0;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=4;++j)
		{
			if(a[i][j]) ++cnt;
		}
		if(cnt==1) printf("D ");
		if(cnt==2) printf("K ");
		if(cnt==3) printf("G ");
		if(cnt==4) printf("U ");
		if(cnt==0) printf("M ");
		cnt=0;
	}
	printf("\n");
	return 0;
}