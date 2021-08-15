#include <stdio.h>

int main()
{
	int r, e, c;
	scanf("%d %d %d",&r, &e, &c);
	e-=c;
	if(r<e) printf("advertise\n");
	else if(r>e) printf("do not advertise\n");
	else printf("does not matter\n");
	return 0;
}