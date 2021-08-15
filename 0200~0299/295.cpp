#include <stdio.h>
int main(){
    int i,n,m=1,t,cnt=0;
    scanf("%d",&n);
    for(i=2;i<=n;++i){
        for(t=i;t%2==0;t/=2,++cnt);
        for(;t%5==0;t/=5,--cnt);
        m=(m*t)%10;
    }
    for(;cnt--;)m=(m*2)%10;
    printf("%d",m);
    return 0;
}
