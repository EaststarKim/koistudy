#include <stdio.h>
int a[310],D[31][310],x[31][310];
void seek(int p,int v)
{
    int t;
    if(p==1)
    {
        t=(v+1)/2;
        printf("%d ",a[t]-a[t-1]);
        return;
    }
    seek(p-1,x[p][v]);
    t=(v+x[p][v]+1)/2;
    printf("%d ",a[t]-a[t-1]);
}
int main()
{
	int i,j,k,n,p,t,mn,s;
	scanf("%d%d",&n,&p);
	for(i=1;i<=n;++i)scanf("%d",&a[i]),a[i]+=a[i-1];
	for(i=1;i<=n-p+1;++i)
	{
		t=(i+1)/2;
		D[1][i]=(a[t]-a[t-1])*(t-1)-a[t-1]+a[i]-a[t]-(a[t]-a[t-1])*(i-t);
		x[1][i]=t;
	}
	for(i=2;i<=p;++i)
	{
		for(j=i;j<=n-p+i;++j)
		{
		    mn=3000001;
			for(k=i-1;k<j;++k)
			{
				t=(j+k+1)/2;
				s=D[i-1][k]+(a[t]-a[t-1])*(t-k-1)-a[t-1]+a[k]+a[j]-a[t]-(a[t]-a[t-1])*(j-t);
				if(mn>s)mn=s,x[i][j]=k;
			}
			D[i][j]=mn;
		}
	}
	printf("%d\n",D[p][n]);
	seek(p,n);
	return 0;
}
