#include <stdio.h>
int main(){
    int i,n,l,r,m;
    long long x;
    scanf("%d%lld",&n,&x);
    for(l=3,r=n;l<=r;){
        m=(l+r)/2;
        if((long long)(m-1)*(m-2)/2<x)l=m+1;
        else r=m-1,i=m;
    }
    if(r==n){
        puts("-1");
        return 0;
    }
    for(;n>i;--n)printf("%d ",n);
    m=x-(long long)(n-1)*(n-4)/2;
    printf("%d ",n);
    for(i=1;i<n;++i)if(i!=m)printf("%d ",i);
    printf("%d",m);
    return 0;
}
