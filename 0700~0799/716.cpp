#include <stdio.h>
int in[101],length,finish,sum,max;
void check(int count,int len,int plen)
{
	int j;
	--in[plen];
	if(count==0)finish=1;
	if(!finish)
	{
		len-=plen;
		if(len!=0)
		{
			j=len<plen?len:plen;
			for(;j>0;--j)
			{
				if(in[j])check(count,len,j);
			}
		}
		else
		{
			for(j=100;!in[j];--j);
			check(count-1,length,j);
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
		sum+=b;
		if(max<b)max=b;
	}
	for(length=max;!finish;++length)
	{
		if(sum%length==0)check(sum/length,length,max);
	}
	printf("%d",length-1);
	return 0;
}
