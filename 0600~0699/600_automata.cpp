#include <stdio.h>
int a[100001],b[2][3]={{0,2,1},{1,0,2}},k;
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%1d",&a[i]);
		k=b[a[i]][k];
	}
	if(k)printf("False");
	else printf("True");
	return 0;
}