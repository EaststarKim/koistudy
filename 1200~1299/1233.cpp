#include <stdio.h>
int main(){
    int i,h,t;
    long long n,l,r,m,s=0;
    scanf("%d%lld",&h,&n);
    l=1,r=1ll<<h;
    for(i=1,t=0;i<=h;++i,t=!t){
        m=(l+r)/2;
        ++s;
        if((t&&n<=m)||(!t&&n>m))s+=(1ll<<(h-i+1))-1,t=!t;
        if(n>m)l=m+1;
        else r=m;
    }
    printf("%lld",s);
    return 0;
}
