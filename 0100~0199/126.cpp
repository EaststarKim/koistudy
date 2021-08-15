#include <stdio.h>

int a[10010];

int main()
{
	int i, n, max, min, mxi, mni;
	scanf("%d",&n);
	for(i=1;i<=n;++i) scanf("%d",&a[i]);
	max=0;
	min=1000000;
	for(i=1;i<=n;++i)
	{
		if(max<a[i]) max=a[i], mxi=i;
		if(min>a[i]) min=a[i], mni=i;
	}
	printf("%d : %d\n%d : %d\n",mxi, max, mni, min);
	return 0;
}