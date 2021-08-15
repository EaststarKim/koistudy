#include <stdio.h>
int in[101],l,f,s,max;
void check(int cnt,int len,int plen)
{
	int j;
	--in[plen];
	if(!cnt)f=1;
	if(!f)
	{
		len-=plen;
		if(len)
		{
			j=len<plen?len:plen;
			for(;j>0;--j)
			{
				if(in[j])check(cnt,len,j);
			}
		}
		else
		{
			for(j=max;!in[j];--j);
			check(cnt-1,l,j);
		}
	}
	++in[plen];
}
int main()
{
	int b,n;
	scanf("%d",&n);
	for(;n--;)
	{
		scanf("%d",&b);
		++in[b];
		s+=b;
		if(max<b)max=b;
	}
	for(l=max;!f;++l)
	{
		if(s%l==0)check(s/l,l,max);
	}
	printf("%d",l-1);
	return 0;
}
