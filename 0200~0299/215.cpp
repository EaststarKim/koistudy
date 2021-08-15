#include <stdio.h>
char a[100001];
int main()
{
	int i,m,t,u,f,d;
	scanf("%d%d%d%d%d",&m,&t,&u,&f,&d);
	for(i=1;i<=t;++i)scanf("%c%c",&a[0],&a[i]);
	for(i=1;i<=t;++i)
	{
		if((a[i]=='u'||a[i]=='d')&&m>=u+d)m-=u+d;
		else if(a[i]=='f'&&m>=2*f)m-=2*f;
		else break;
	}
	printf("%d",i-1);
	return 0;
}