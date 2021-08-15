#include <stdio.h>
#include <algorithm>
#include <math.h>
struct data
{
    int d,p;
    bool operator<(const data&r)const
    {
        return d<r.d;
    }
}a[10010];
int main()
{
    int i,n,p,x,y;
    scanf("%d%d",&n,&p);
    for(i=1;i<=n;++i)
    {
        scanf("%d%d%d",&x,&y,&a[i].p);
        a[i].d=x*x+y*y;
    }
    std::sort(a+1,a+n+1);
    for(i=1;i<=n;++i)
    {
        p+=a[i].p;
        if(p>999999)break;
    }
    if(i>n)printf("-1");
    else printf("%.3lf",sqrt(double(a[i].d)));
    return 0;
}
