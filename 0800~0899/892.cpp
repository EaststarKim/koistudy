#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int g,d;
    bool operator<(const data&r)const{
        return d>r.d;
    }
}a[10010];
int h[10010],p,s;
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;++i)scanf("%d%d",&a[i].g,&a[i].d);
    sort(a,a+n);
    for(j=0,i=a[0].d;i>0;--i){
        for(;a[j].d==i;++j)h[p++]=a[j].g,push_heap(h,h+p);
        if(p){
            s+=h[0];
            pop_heap(h,h+p);
            --p;
        }
    }
    printf("%d",s);
    return 0;
}
