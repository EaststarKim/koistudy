#include <stdio.h>
#include <algorithm>
int a[6][6],rs,cs;
int main()
{
	int i,j,m1,m2;
	for(i=1;i<6;++i)
	{
		for(j=1;j<6;++j)scanf("%d",&a[i][j]);
	}
	for(i=1;i<6;++i)
	{
		m1=m2=0;
		for(j=1;j<6;++j)
		{
			if(m1<a[i][j])m1=a[i][j];
			if(m2<a[j][i])m2=a[j][i];
		}
		rs+=m1;
		cs+=m2;
	}
	printf("%d",abs(rs-cs));
	return 0;
}
