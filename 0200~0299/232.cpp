#include <stdio.h>
char a[15];
int main()
{
	int i,k;
	scanf("%s",a+1);
	k=a[8]-48;
	if(k<3)printf("19");
	else printf("20");
	printf("%d%d",a[1]-48,a[2]-48);
	for(i=4;i<7;i+=2)printf("/%d%d",a[i-1]-48,a[i]-48);
	if(k%2)printf(" M");
	else printf(" F");
	return 0;
}