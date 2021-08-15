#include <stdio.h>
int a[100010],b[110],c[110],cnt=1;
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]),++b[a[i]];
	for(i=100;i>=0;--i)c[i]=cnt,cnt+=b[i];
	for(i=1;i<=n;++i)printf("%d\n",c[a[i]]);
	return 0;
}