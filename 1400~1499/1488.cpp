#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int s,e;
    bool operator<(const data&r)const{
        return s<r.s;
    }
}a[25010];
int main(){
    int i,n,t,e=0,cnt=0,mx;
    scanf("%d%d",&n,&t);
    for(i=1;i<=n;++i)scanf("%d%d",&a[i].s,&a[i].e);
    sort(a+1,a+n+1);
    for(i=1;;){
        mx=e;
        for(;i<=n;++i){
            if(a[i].s>e+1)break;
            mx=max(mx,a[i].e);
        }
        if(mx==e){
            if(e<t)puts("-1");
            else printf("%d",cnt);
            return 0;
        }
        e=mx;
        ++cnt;
        if(e>=t){
            printf("%d",cnt);
            return 0;
        }
    }
}
