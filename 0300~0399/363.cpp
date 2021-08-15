#include <cstdio>     
#include <algorithm>     
struct G     
{     
    int x,y,z;     
    bool operator()(G a,G b)     
    {     
        return a.x<b.x;     
    }     
}a[10010];     
int q[10010],b[10010],ans[10010],p;     
int main()     
{     
    int i,n,l,r,h,k,t;     
    scanf("%d",&n);     
    for(i=1;i<=n;++i)scanf("%d",&t),a[t].x=i,a[t].z=t;     
    for(i=1;i<=n;++i)scanf("%d",&t),a[t].y=i;     
    std::sort(a+1,a+n+1,G());     
    for(i=1;i<=n;++i)     
    {     
        if(a[q[p]].y<a[i].y)     
        {     
            q[++p]=i;     
            b[i]=q[p-1];     
        }     
        else     
        {     
            l=1;     
            r=p;     
            while(l<=r)     
            {     
                h=(l+r)/2;     
                if(l==r)     
                {     
                    q[l]=i;     
                    b[i]=q[l-1];     
                    break;     
                }     
                if(a[q[h]].y<a[i].y)l=h+1;     
                if(a[q[h]].y>a[i].y)r=h;     
            }     
        }     
    }     
    printf("%d\n",p);     
    k=q[p];     
    while(k)     
    {     
        t=b[k];     
        b[k]=-1;     
        k=t;     
    }     
    p=0;     
    for(i=1;i<=n;++i)     
    {     
        if(b[i]==-1)ans[++p]=a[i].z;     
    }     
    std::sort(&ans[1],&ans[p+1]);     
    for(i=1;i<=p;++i)printf("%d ",ans[i]);     
    return 0;     
}  