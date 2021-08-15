#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int i,s,t;
    bool operator<(const data&r)const{
        return s+r.s*t>r.s+s*r.t;
    }
}a[10010];
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;++i)scanf("%d%d",&a[i].s,&a[i].t),a[i].i=i;
    sort(a,a+n);
    for(i=0;i<n;++i)printf("%d\n",a[i].i+1);
    return 0;
}
