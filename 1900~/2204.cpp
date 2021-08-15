#include <stdio.h>
char a[110],b[110];
int main(){
	int i,n,ans=0;
	scanf("%d",&n);
	scanf("%s%s",a,b);
	for(i=0;i<n;++i)if(a[i]==67&&b[i]==67)++ans;
	printf("%d",ans);
	return 0;
}
