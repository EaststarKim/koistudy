#include <stdio.h>
int a[100010],st[100010];
int main()
{
    int i,j,t,n,p,cnt;
    scanf("%d",&t);
    for(i=1;i<=t;++i){
        scanf("%d",&n);
        for(j=1;j<=n;++j)scanf("%d",a+j);
        p=cnt=0;
        for(j=n;j>0;--j){
            if(a[j]==cnt+1){
                ++cnt;
                continue;
            }
            while(p&&st[p]==cnt+1)--p,++cnt;
            st[++p]=a[j];
        }
        while(p&&st[p--]==cnt+1)++cnt;
        if(cnt==n)puts("Y");
        else puts("N");
    }
    return 0;
}
