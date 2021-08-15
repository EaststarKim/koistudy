#include <stdio.h>
int ans[20000]={1},k,cnt;
int main()
{
    int a,b,d,n,i;
    scanf("%d %d %d %d",&a,&b,&d,&n);
    for(i=0;i<n;++i)
    {
        k=(k+1)%d;
        cnt+=ans[(k-a+d)%d];
        cnt-=ans[(k-b+d)%d];
        cnt=(cnt+1000)%1000;
        ans[k]=cnt;
    }
    cnt=0;
    for(i=0;i<d;++i)
    {
		cnt+=ans[i];
        cnt%=1000;
    }
    printf("%d",cnt);
    return 0;
}