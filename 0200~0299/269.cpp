#include <stdio.h>
#include <string.h>
int a[14][30],chk[14],cnt,n,q;
void back(int p)
{
    int i=1;
    if(p>n)
    {
        ++cnt;
		if(q<3)
		{
			for(;i<=n;++i)printf("%d ",chk[i]);
			printf("\n");
			++q;
		}
        return;
    }
    memset(a[p],0,sizeof(a[p]));
    for(;i<p;++i)
    {
        a[p][chk[i]]=a[p][chk[i]+p-i]=1;
        if(chk[i]-p+i>0)a[p][chk[i]-p+i]=1;
    }
    for(i=1;i<=n;++i)
    {
        if(a[p][i]==0)
        {
            chk[p]=i;
            back(p+1);
        }
    }
}
int main()
{
    int i,m;
    scanf("%d",&n);
	if(n>6)m=n/2;
	else m=n;
    for(i=1;i<=m;++i)
    {
        chk[1]=i;
        back(2);
        memset(chk,0,sizeof(chk));
        memset(a,0,sizeof(a));
    }
	if(n>6)cnt*=2;
	if(n>6&&n%2)
	{
		chk[1]=m+1;
		back(2);
	}
	printf("%d",cnt);
    return 0;
}