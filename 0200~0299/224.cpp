#include <stdio.h>
unsigned long long i,s,e,ans;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(i=1;e<n;i*=2){
        s=e+1;
        e=(i*2-1)/k;
        if(e>n)e=n;
        ans+=((s*k)%i*2+1+k*(e-s))*(e-s+1);
    }
    printf("%llu",ans);
    return 0;
}
