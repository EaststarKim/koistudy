#include <stdio.h>
int a[6][6],b[26],c[2][26],bc;
int main()
{
	int i,j,k,m;
	for(i=1;i<6;++i)
	{
		for(j=1;j<6;++j)
		{
			scanf("%d",&m);
			a[i][j]=m;
			c[0][m]=i;
			c[1][m]=j;
		}
	}
	for(i=1;i<26;++i)scanf("%d",&b[i]);
	for(i=1;i<26;++i)
	{
		bc=0;
		a[c[0][b[i]]][c[1][b[i]]]=0;
		for(j=1;j<6;++j)
		{
			for(k=1;k<6;++k)
			{
				if(a[j][k])break;
			}
			if(k>5)++bc;
			for(k=1;k<6;++k)
			{
				if(a[k][j])break;
			}
			if(k>5)++bc;
		}
		for(j=1;j<6;++j)
		{
			if(a[j][j])break;
		}
		if(j>5)++bc;
		for(j=1;j<6;++j)
		{
			if(a[j][6-j])break;
		}
		if(j>5)++bc;
		if(bc>2)break;
	}
	printf("%d",i);
	return 0;
}