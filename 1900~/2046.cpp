#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    long long w,h;
    bool operator<(const data&r)const{
        if(w==r.w)return h<r.h;
        return w<r.w;
    }
}a[50010];
int q[50010],p,f,r;
long long D[50010];
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%lld%lld",&a[i].w,&a[i].h);
    sort(a+1,a+n+1);
    for(i=1;i<=n;++i){
        while(p&&a[p].h<=a[i].h)--p;
        a[++p]=a[i];
    }
    for(i=1;i<=p;++i){
        while(f<r&&a[q[f]+1].h*a[i].w+D[q[f]]>=a[q[f+1]+1].h*a[i].w+D[q[f+1]])++f;
        D[i]=a[q[f]+1].h*a[i].w+D[q[f]];
        while(f<r&&(D[q[r]]-D[q[r-1]])*(a[i+1].h-a[q[r-1]+1].h)<=(D[i]-D[q[r-1]])*(a[q[r]+1].h-a[q[r-1]+1].h))--r;
        q[++r]=i;
    }
    printf("%lld",D[p]);
    return 0;
}
