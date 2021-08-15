#include <stdio.h>
int a[520]={0,1},b[520],m;
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<n;++i)
	{
		for(j=1;j<=m;++j)
		{
			a[m+j+1]=a[j];
			if(b[j]==1)b[m+j+1]=3;
			else if(b[j]==2)b[m+j+1]=4;
			else if(b[j]==3)b[m+j+1]=1;
			else if(b[j]==4)b[m+j+1]=2;
			else if(b[j]==5)b[m+j+1]=6;
			else b[m+j+1]=5;
		}
		for(j=1;j<=m;++j)
		{
			if(b[j]==1)b[j]=2;
			else if(b[j]==2)b[j]=1;
			else if(b[j]==3)b[j]=5;
			else if(b[j]==4)b[j]=6;
			else if(b[j]==5)b[j]=3;
			else b[j]=4;
		}
		a[j]=i;
		b[j]=2;
		m+=m+1;
	}
	m+=m+1;
	printf("%d\n",m);
	--m;
	m/=2;
	for(i=1;i<=m;++i)
	{
		printf("move disk %d ",a[i]);
		if(b[i]==1)printf("A->C");
		else if(b[i]==2)printf("A->B");
		else if(b[i]==3)printf("C->A");
		else if(b[i]==4)printf("C->B");
		else if(b[i]==5)printf("B->A");
		else printf("B->C");
		printf("\n");
	}
	printf("move disk %d A->C\n",n);
	for(i=1;i<=m;++i)
	{
		printf("move disk %d ",a[i]);
		if(b[i]==1)printf("B->A");
		else if(b[i]==2)printf("B->C");
		else if(b[i]==3)printf("A->B");
		else if(b[i]==4)printf("A->C");
		else if(b[i]==5)printf("C->B");
		else printf("C->A");
		printf("\n");
	}
	return 0;
}