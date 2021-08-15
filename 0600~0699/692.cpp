#include <stdio.h>
short chk[7500001];
bool count[15000001];
bool check(register int a,register int b)
{
	register int aa=a,bb=b;
aa:
	aa>bb? aa%=bb:bb%=aa;
	if(!aa||!bb)goto bb;
	goto aa;
bb:
	return (aa+bb==1)? true:false;
}
int main()
{
	register int n,i=2,j,c=0,t,st;
	scanf("%d",&n);
	st=n/2;
aa:
	if(i>st)goto bb;
	if(i%2)
	{
		j=2;
cc:
		if(j>i)goto dd;
		if(i+j>st/i)goto dd;
		t=i*(i+j);
		if(check(i,j))count[t]=true;
		j+=2;
		goto cc;
	}
	else
	{
		j=1;
ee:
		if(j>i)goto dd;
		if(i+j>st/i)goto dd;
		t=i*(i+j);
		if(check(i,j))count[t]=true;
		j+=2;
		goto ee;
	}
dd:
	if(count[i]&&chk[i]<=1)
	{
		j=i;
xx:
		if(j>st)goto yy;
		++chk[j];
		j+=i;
		goto xx;
	}
yy:
	if(chk[i]==1)++c;
	++i;
	goto aa;
bb:
	printf("%d",c);
	return 0;
}