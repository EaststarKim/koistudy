#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
struct data{
    int d,p;
    bool operator<(const data&r)const{
        return d>r.d;
    }
}a[100010];
int h[100010],p;
long long s;
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d%d",&a[i].d,&a[i].p);
    sort(a+1,a+n+1);
    for(j=1,i=a[1].d;i;){
        for(;a[j].d==i;++j)h[p++]=a[j].p,push_heap(h,h+p);
        if(p){
            s+=h[0];
            pop_heap(h,h+p);
            --p;
            --i;
        }
        else i=a[j].d;
    }
    printf("%lld",s);
    return 0;
}
