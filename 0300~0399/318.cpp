#include <stdio.h>   
#include <algorithm>   
struct G   
{   
    int x,y;   
    bool operator()(G a,G b)   
    {   
        return a.x<b.x;   
    }   
}a[110];   
int b[110];   
int main()   
{   
    int i,j,n,mx=0;   
    scanf("%d",&n);   
    for(i=1;i<=n;++i)scanf("%d%d",&a[i].x,&a[i].y);   
    std::sort(a+1,a+n+1,G());   
    for(i=1;i<=n;++i)   
    {   
        b[i]=1;   
        for(j=1;j<i;++j)   
        {   
            if(a[i].y>a[j].y&&b[i]<b[j]+1)b[i]=b[j]+1;   
        }   
        if(mx<b[i])mx=b[i];   
    }   
    printf("%d",n-mx);   
    return 0;   
}  