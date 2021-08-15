#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
struct data{
    int x,y;
    bool operator<(const data&r)const{
        if(x==r.x)return y<r.y;
        return x<r.x;
    }
}a[100010],mx[100010],mn[100010];
int xf=1,xr,nf=1,nr;
int main(){
    int i,n,d,ans=2e9;
    scanf("%d%d",&n,&d);
    for(i=1;i<=n;++i)scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+n+1);
    for(i=1;i<=n;++i){
        while(xf<=xr&&mx[xr].y<=a[i].y)--xr;
        mx[++xr]=a[i];
        while(nf<=nr&&mn[nr].y>=a[i].y)--nr;
        mn[++nr]=a[i];
        while(xf<=xr&&nf<=nr&&mx[xf].y-mn[nf].y>=d){
            ans=min(ans,a[i].x-min(mx[xf].x,mn[nf].x));
            if(mx[xf].x<=mn[nf].x)++xf;
            if(mx[xf].x>=mn[nf].x)++nf;
        }
    }
    if(ans==2e9)ans=-1;
    printf("%d",ans);
    return 0;
}
