#include <stdio.h>

char a[8];

int main()
{
	int i, k;
	scanf("%d",&k);
	scanf("%s",a);
	for(i=0;i<8;++i) printf("%c",a[i]+k);
	return 0;
}