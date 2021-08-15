#include <stdio.h>
int n;
char a[10000];
void back(int p)
{
	if(p==n)return;
	a[p]='*';
	printf("%s\n",a);
	back(p+1);
}
int main()
{
	scanf("%d",&n);
	back(0);
	return 0;
}