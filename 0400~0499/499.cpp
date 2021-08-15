#include <stdio.h>      
#include <algorithm>      
struct G      
{      
    int x,y;      
    bool operator()(G a,G b)      
    {      
        return a.x+a.y<b.x+b.y;      
    }      
}a[1001];      
int main()      
{      
    int i,j,n,b,mx=0,s;      
    scanf("%d%d",&n,&b);      
    for(i=1;i<=n;++i)scanf("%d%d",&a[i].x,&a[i].y);      
    std::sort(&a[1],&a[n+1],G());      
    for(i=1;i<=n;++i)      
    {      
        s=a[i].x/2+a[i].y;   
        if(s<=b)   
        {   
            for(j=1;j<=n;++j)      
            {      
                if(j!=i)   
                {   
                    if(s+a[j].x+a[j].y>b)break;      
                    s+=a[j].x+a[j].y;   
                }   
            }    
            --j;      
            if(i>j)++j;      
            if(mx<j)mx=j;   
        }   
    }      
    printf("%d",mx);      
    return 0;      
}