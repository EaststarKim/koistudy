#include <stdio.h>
int cnt,n;
void back(int n)
{
	++cnt;
	if(n==1)return;
	if(n%2)back(3*n+1);
	else back(n/2);
}
int main()
{
	scanf("%d",&n);
	back(n);
	printf("%d",cnt);
	return 0;
}