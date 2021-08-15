#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[12];

int main()
{
	int i, n, k, l;
	scanf("%d",&n);
	srand(time(NULL));
	for(i=1;i<=n;++i)
	{
		k=l=0;
		while(k==0) k=rand()%7;
		while(l==0) l=rand()%7;
		++a[k+l];
	}
	for(i=2;i<=12;++i) printf("%d ",a[i]);
	return 0;
}