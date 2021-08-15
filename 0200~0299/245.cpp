#include <stdio.h>
#include <math.h>
#include <algorithm>
int a[7],chk[7],b[721],n,cnt;
void back(int s,int p)
{
	int i,m;
	if(p>n)
	{
		m=(int)sqrt(s);
		for(i=2;i<=m;++i)
		{
			if(!(s%i))break;
		}
		if(s>1&&i>m)b[++cnt]=s;
		return;
	}
	for(i=1;i<=n;++i)
	{
		if(!chk[i])
		{
			chk[i]=1;
			back(s*10+a[i],p+1);
			chk[i]=0;
		}
	}
}
int main()
{
	int i,k;
	scanf("%d",&k);
	while(k)
	{
		a[++n]=k%10;
		k/=10;
	}
	std::sort(&a[1],&a[n+1]);
	back(0,1);
	if(cnt)
	{
		std::sort(&b[1],&b[cnt+1]);
		for(i=1;i<=cnt;++i)
		{
			if(b[i]!=b[i-1])printf("%d ",b[i]);
		}
	}
	else printf("0");
	return 0;
}