#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100010];
long long ans;
int main(){
    int i,n,t;
    scanf("%d",&n);
    for(i=0;i<n;++i){
        scanf("%d",a+i);
        a[i]=-a[i];
        push_heap(a,a+i);
    }
    for(;n>1;){
        t=a[0];
        pop_heap(a,a+n);
        t+=a[0],ans-=t;
        --n;
        pop_heap(a,a+n);
        a[n-1]=t;
        push_heap(a,a+n);
    }
    printf("%lld",ans);
    return 0;
}
