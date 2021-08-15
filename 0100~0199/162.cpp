#include <stdio.h>
#include <string.h>

char a[5];

int main()
{
	int i, m;
	scanf("%s",a);
	m=strlen(a);
	for(i=0;i<m;++i) printf("%c",a[i]-32);
	return 0;
}