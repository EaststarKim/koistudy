#include <stdio.h>
#include <math.h>
int cnt,n,x;
void back(int k,int r,int ld,int rd)
{
    int p,a;
    if(k>n)
    {
        ++cnt;
        return;
    }
    a=r|ld|rd;
    while(1)
    {
        p=(~a)&(a+1);
        if(p>=x)return;
        a|=p;
        back(k+1,r|p,(ld|p)>>1,(rd|p)<<1);
    }
}
int main()
{
    int i,m,t=1;
    scanf("%d",&n);
    x=pow(2,n);
	m=n/2;
    for(i=1;i<=m;++i)
    {
        back(2,t,t>>1,t<<1);
        t<<=1;
    }
	printf("%d",cnt*2);
    return 0;
}
