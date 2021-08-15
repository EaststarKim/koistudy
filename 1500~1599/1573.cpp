#include <stdio.h>
#define M 1000000007
long long f[200010]={1};
int pow(long long a,int n){
    int i;
    long long ans=1;
    for(i=0;i<30;++i){
        if(n&(1<<i))ans=ans*a%M;
        a=a*a%M;
    }
    return ans;
}
int main(){
    int i,n,m,k;
    scanf("%d%d%d",&n,&k,&m);
    for(i=1;i<=n;++i)f[i]=f[i-1]*i%M;
    printf("%d",f[n-1]*pow(f[m],M-2)%M*pow(f[n-m-1],M-2)%M*k%M*pow(k-1,m)%M);
    return 0;
}
