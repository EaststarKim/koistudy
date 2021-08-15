#include <stdio.h>
int n;
char a[21];
void back(int p)
{
	if(p*2>n)
	{
		printf("%c ",a[p-1]);
		return ;
	}
	back(p*2);
	printf("%c ",a[p-1]);
	if(p*2<n)back(p*2+1);
}
int main()
{
	scanf("%d",&n);
	scanf("%s",a);
	back(1);
	return 0;
}