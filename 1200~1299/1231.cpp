#include <stdio.h>
int main(){
    int i,n,g=1,b=0;
    long long s=0;
    scanf("%d",&n);
    for(i=0;n>=g;++i){
        s+=g+b;
        n-=g;
        g^=b^=g^=b;
        b+=g;
    }
    if(n==0)printf("%lld %d",s,i-1);
    else puts("-1");
    return 0;
}
