#include <stdio.h>
int n;
char a[21];
void back(int p)
{
	printf("%c ",a[p-1]);
	if(p*2<=n)back(p*2);
	if(p*2+1<=n)back(p*2+1);
}
int main()
{
	scanf("%d",&n);
	scanf("%s",a);
	back(1);
	return 0;
}