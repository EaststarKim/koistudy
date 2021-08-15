#include <stdio.h>
int main(){
    long long N,L,W,H,l=0,r=1e14,m,ans;
    scanf("%lld%lld%lld%lld",&N,&L,&W,&H);
    L*=1e5,W*=1e5,H*=1e5;
    while(l<r){
        m=(l+r)/2;
        if((L/m)*(W/m)*(H/m)>=N)ans=m,l=m+1;
        else r=m-1;
    }
    printf("%.6lf",(double)ans/1e5);
    return 0;
}
