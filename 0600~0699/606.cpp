#include <stdio.h>
int cnt;
void h(int n,int f,int m,int t)
{
	if(n>0)
	{
		h(n-1,f,m,t);
		printf("%d : %c->%c\n",n,f,t);
		h(n-1,m,f,t);
		printf("%d : %c->%c\n",n,t,m);
		h(n-1,f,m,t);
		cnt+=2;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	h(n,65,67,66);
	printf("%d",cnt);
	return 0;
}