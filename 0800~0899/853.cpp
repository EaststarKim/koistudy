#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int x,y;
}a[310];
int t,s,ans,mx1,mx2;
int main()
{
    int i,j,k,l,n,dx,dx1,dy,dy1,d;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d%d",&a[i].x,&a[i].y);
    for(i=1;i<n;++i){
        for(j=i+1;j<=n;++j){
            mx1=mx2=0;
            t=a[i].x*a[j].y-a[j].x*a[i].y;
            dx=a[i].x-a[j].x;
            dy=a[i].y-a[j].y;
            for(k=1;k<=n;++k){
                if(k==i||k==j)continue;
                s=t+a[j].x*a[k].y+a[k].x*a[i].y-a[i].x*a[k].y-a[k].x*a[j].y;
                if(s<0)s=-s;
                dx1=a[k].x-a[j].x,dy1=a[k].y-a[j].y;
                d=dx1*dy-dx*dy1;
                if(d>0)mx1=max(mx1,s);
                else mx2=max(mx2,s);
            }
            if(mx1&&mx2)ans=max(ans,mx1+mx2);
        }
    }
    printf("%.1lf",(double)ans/2);
    return 0;
}
