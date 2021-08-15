#include <stdio.h>
#include <string.h>
char a[401];
int b[2][9]={{5,2,3,3,5,6,3,6,8},{1,8,8,4,7,0,0,7,8}},k;
int main()
{
	int i,n;
	scanf("%s",a);
	n=strlen(a);
	for(i=0;i<n;++i)k=b[a[i]-48][k];
	if(k==0||k==4)printf("SUB");
	else printf("Not SUB");
	return 0;
}