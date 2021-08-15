#include <stdio.h>
int a[10][10],chk[82][10],b[10][10],cnt;
void back(int p)
{
	int i,j,k,l;
	for(i=1;i<10;++i)
	{
		for(j=1;j<10;++j)
		{
			if(!a[i][j])break;
		}
		if(j<10)break;
	}
	if(i>9)
	{
		++cnt;
		for(i=1;i<10;++i)
		{
			for(j=1;j<10;++j)b[i][j]=a[i][j];
		}
		return;
	}
	for(k=1;k<10;++k)
	{
		if(a[i][k])chk[p][a[i][k]]=1;
		if(a[k][j])chk[p][a[k][j]]=1;
	}
	for(k=1;k<4;++k)
	{
		for(l=1;l<4;++l)
		{
			if(a[(i-1)/3*3+k][(j-1)/3*3+l])chk[p][a[(i-1)/3*3+k][(j-1)/3*3+l]]=1;
		}
	}
	for(k=1;k<10;++k)
	{
		if(!chk[p][k])
		{
			a[i][j]=k;
			back(p+1);
			a[i][j]=0;
		}
	}
	for(k=1;k<10;++k)chk[p][k]=0;
}
int main()
{
	int i,j,k,l,sw;
	for(i=1;i<10;++i)
	{
		for(j=1;j<10;++j)scanf("%d",&a[i][j]);
	}
	for(i=1;i<10;++i)
	{
		for(j=1;j<10;++j)
		{
			sw=1;
			for(k=1;k<10;++k)
			{
				if(a[i][k])chk[0][a[i][k]]=1;
				if(a[k][j])chk[0][a[k][j]]=1;
			}
			for(k=1;k<4;++k)
			{
				for(l=1;l<4;++l)
				{
					if(a[(i-1)/3*3+k][(j-1)/3*3+l])chk[0][a[(i-1)/3*3+k][(j-1)/3*3+l]]=1;
				}
			}
			for(k=1;k<10;++k)
			{
				if(chk[0][k])sw=0;
				chk[0][k]=0;
			}
			if(sw)break;
		}
		if(sw)break;
	}
	if(!sw)back(1);
	if(!cnt)printf("impossible");
	else if(cnt==1)
	{
		for(i=1;i<10;++i)
		{
			for(j=1;j<10;++j)printf("%d ",b[i][j]);
			printf("\n");
		}
	}
	else printf("%d",cnt);
	return 0;
}
