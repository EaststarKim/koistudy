#include <stdio.h>
#include <algorithm>
using namespace std;
struct point{
    long long x,y,t;
    bool operator<(const point&r)const{
        return y*r.x<x*r.y;
    }
}p[20010];
int main(){
    int i,n,a,b,c,d;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        p[i*2-1]={a,d,0},p[i*2]={c,b,1};
    }
    sort(p+1,p+n*2+1);
    int s,t=0,ans=0;
    for(i=1;i<=n*2;){
        s=0;
        for(;i<=n*2;){
            if(p[i].t)++t;
            else ++s;
            ++i;
            if(p[i-1].y*p[i].x!=p[i-1].x*p[i].y)break;
        }
        if(ans<t)ans=t;
        t-=s;
    }
    printf("%d",ans);
    return 0;
}
