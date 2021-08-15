#include <stdio.h>   
#include <algorithm>   
struct G   
{   
    int x,y,z;   
    bool operator()(G a,G b)   
    {   
        return a.x<b.x;   
    }   
}a[100010];   
int q[100010],p;   
int main()   
{   
    int i,n,l,r,h;   
    scanf("%d",&n);   
    for(i=1;i<=n;++i)scanf("%d%d",&a[i].x,&a[i].y),a[i].z=i;   
    std::sort(a+1,a+n+1,G());   
    for(i=1;i<=n;++i)   
    {   
        if(a[q[p]].y<a[i].y)q[++p]=i;   
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
                    break;   
                }   
                if(a[q[h]].y<a[i].y)l=h+1;   
                if(a[q[h]].y>a[i].y)r=h;   
            }   
        }   
    }   
    printf("%d\n",n-p);   
    return 0;   
}  