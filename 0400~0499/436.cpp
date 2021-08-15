#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int x[100001],y[100001],aa,bb;
int main()
{
	int i,a,b,n,m,p,q;
	scanf("%d%d",&a,&b);
	n=(int)sqrt(a);
	m=(int)sqrt(b);
	for(i=1;i<n;++i)
	{
		if(!(a%i))x[++aa]=i;
	}
	if(!(a%n))x[++aa]=n;
	for(i=aa;i>0;--i)
	{
		if(a/x[i]!=x[i])x[++aa]=a/x[i];
	}
	for(i=1;i<m;++i)
	{
		if(!(b%i))y[++bb]=i;
	}
	if(!(b%m))y[++bb]=m;
	for(i=bb;i>0;--i)
	{
		if(b/y[i]!=y[i])y[++bb]=b/y[i];
	}
	p=q=1;
	while(p<=aa||q<=bb)
	{
		if(p<=aa&&(q>bb||x[p]<y[q]))printf("%d ",x[p++]);
		else if(q<=bb&&(p>aa||x[p]>y[q]))printf("%d ",y[q++]);
		else
		{
			printf("%d ",x[p++]);
			++q;
		}
	}
	return 0;
}