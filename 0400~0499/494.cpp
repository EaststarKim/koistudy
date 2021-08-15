#include<stdio.h>
int a[1000001],sum[1000001],lmin[1000001],rmin[1000001],b[1000];
int main()
{
    int i,k,t,n,cnt,min;
    scanf("%d",&t);
    for(k=1;k<=t;++k)
	{
        min=1000000001;
        cnt=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        for(i=1;i<=n;i++)
        {
            if(sum[i]<min)
            {
                min=sum[i];
                lmin[i]=min;
            }
            else lmin[i]=min;
        }
        min=1000000001;
        for(i=n;i>=1;i--)
        {
            if(sum[i]<min)
            {
                min=sum[i];
                rmin[i]=min;
            }
            else rmin[i]=min;
        }
        for(i=1;i<=n;++i)
        {
            if((rmin[i]-sum[i-1]>=0) && (lmin[i-1]+sum[n]-sum[i-1]>=0))cnt++;
        }
        b[k]=cnt;
    }
    for(i=1;i<=t;i++)printf("%d\n",b[i]);
    return 0;
}