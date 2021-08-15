#include <stdio.h>
int main()
{
	int i,k,omx,emx;
	omx=emx=0;
	for(i=1;i<=7;++i)
	{
		scanf("%d",&k);
		if(k%2 && omx<k)omx=k;
		if(k%2==0 && emx<k)emx=k;
	}
	printf("%d",omx+emx);
	return 0;
}