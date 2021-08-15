#include <stdio.h>
int n;
char a[18];
void back(int p,int r,int s)
{
	int i;
	if(p>n)
	{
		if(r==0)
		{
			for(i=1;i<=s;++i)printf("%c",a[i]);
			printf("\n");
		}
		return;
	}
	if(p==1)
	{
		a[s]=49;
		a[s+1]=32;
		a[s+2]=50;
		back(p+2,12,s+3);
		back(p+1,1,s+1);
	}
	else
	{
		a[s]=43;
		a[s+1]=p+48;
		if(p<n)
		{
			a[s+2]=32;
			a[s+3]=p+49;
			back(p+2, r+p*10+p+1,s+4);
		}
		back(p+1,r+p,s+2);
		a[s]=45;
		if(p<n)
		{
			a[s+2]=32;
			a[s+3]=p+49;
			back(p+2, r-p*10-p-1,s+4);
		}
		back(p+1,r-p,s+2);
	}
}
int main()
{
	scanf("%d",&n);
	back(1,0,1);
	return 0;
}