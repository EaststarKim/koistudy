#include <stdio.h>   
#include <stdlib.h>   
#include <string.h>   
#include <math.h>   
int a[2][1010],b[1010],q[1000010],n,k,h;   
void BFS()   
{   
    int i,p,f=0,r=1,l;   
    double t;   
    for(i=1;i<=n+1;++i)b[i]=k+1;   
    q[1]=0;   
    while(f<r)   
    {   
        p=q[++f];   
        if(p==n+1)return;   
        for(i=1;i<=n+1;++i)   
        {   
            if(i==p||(i<n+1&&b[i]<b[p]+2)||(i==n+1&&b[i]<b[p]+1))continue;   
            if(b[p]==k)i=n+1;   
            t=sqrt((a[0][i]-a[0][p])*(a[0][i]-a[0][p])+(a[1][i]-a[1][p])*(a[1][i]-a[1][p]))/10;   
            l=(int)t+(t-(int)t>0? 1:0);   
            if(l<=h)   
            {   
                q[++r]=i;   
                if(i<n+1)b[i]=b[p]+1;   
                else b[i]=b[p];   
            }   
        }   
    }   
}   
void bs(int l,int r)   
{   
    h=(l+r)/2;   
    BFS();   
    if(l==r)   
    {   
        printf("%d",l);   
        exit(0);   
    }   
    if(b[n+1]<=k)bs(l,h);   
    else bs(h+1,r);   
}   
int main()   
{   
    int i;   
    scanf("%d%d",&n,&k);   
    for(i=1;i<=n;++i)scanf("%d%d",&a[0][i],&a[1][i]);   
    a[0][n+1]=a[1][n+1]=10000;   
    bs(1,1415);   
    return 0;   
}  