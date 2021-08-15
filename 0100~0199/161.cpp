#include <stdio.h>
#include <string.h>

int a[7];
char x[10];

int main()
{
	int i, m, d, g, c, n, k;
	char y;
	scanf("%2d%2d%2d%c",&d,&m,&d,&y);
	for(i=1;i<=7;++i) scanf("%1d",&a[i]);
	scanf("%1d%1d%2d%c",&g,&c,&n,&y);
	scanf("%s",x);
	printf("%d-%d NO.%d\n",g,c,n);
	k=strlen(x);
	for(i=0;i<k;++i) printf("%c",x[i]);
	if(a[1]%2) printf("(M)\n");
	else printf("(F)\n");
	printf("BirthDay %d/%d\n",m,d);
	return 0;
}