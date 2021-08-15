#include <stdio.h>
int main(){
	int n,t;
	scanf("%d",&n);
	for(t=1;t<n;t*=2);
	printf("%d",n*2-t);
	return 0;
}
