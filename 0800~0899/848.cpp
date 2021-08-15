#include <stdio.h>
#include <stdlib.h>
int a[100010],n;
long long f(int x){
    long long i,s=0;
    for(i=1;i<n;++i)s+=llabs(i*x-a[i]);
    return s;
}
int main(){
    int i,l=1,r,m;
    long long ans;
    scanf("%d",&n);
    for(i=0;i<n;++i)scanf("%d",a+i);
    r=1e9/n;
    while(l<=r){
        m=(l+r)/2;
        ans=f(m);
        if(f(m-1)<ans)r=m-1;
        else if(f(m+1)<ans)l=m+1;
        else break;
    }
    printf("%lld",ans);
    return 0;
}
