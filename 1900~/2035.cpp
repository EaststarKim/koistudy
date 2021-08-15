#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100010],t;
long long s;
struct heap{
    int i;
    long long t;
    heap(){}heap(int i,long long t):i(i),t(t){}
    bool operator<(const heap&r)const{
        return s-t+a[i]<s-r.t+a[r.i];
    }
}h[100010];
int main(){
    int i,n,l,k;
    scanf("%d%d",&n,&l);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i<=n;++i)if(a[i]>a[i-1]&&a[i]>a[i+1])h[t++]=heap(i,0),push_heap(h,h+t);
    for(i=1;i<=n;++i){
        k=h[0].i;
        s+=l-s+h[0].t-a[k];
        a[k]=0;
        pop_heap(h,h+t--);
        if(k>1&&a[k-2]<a[k-1])h[t++]=heap(k-1,s),push_heap(h,h+t);
        if(a[k+1]>a[k+2])h[t++]=heap(k+1,s),push_heap(h,h+t);
    }
    printf("%lld",s);
    return 0;
}
