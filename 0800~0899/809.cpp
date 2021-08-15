#include <stdio.h>
#define M 100000007
typedef long long L;
L fac[10010]={1},s,t;
int pow(L x,int n){
    if(!n)return 1;
    L m=pow(x*x%M,n/2);
    if(n&1)m*=x;
    return m%M;
}
int inv(int n){return pow(n,M-2);}
int com(int n,int m){return fac[n]*inv(fac[n-m])%M*inv(fac[m])%M;}
int main(){
    int i,n,k;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;++i)fac[i]=fac[i-1]*i%M;
    for(i=0;i<=k;++i){
        t=fac[n-i]*com(k,i)%M;
        s=(s+(i%2?-1:1)*t+M)%M;
    }
    printf("%d",s);
    return 0;
}
