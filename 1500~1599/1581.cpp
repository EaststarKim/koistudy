#include <stdio.h>
#define M 1000000007
long long pow(long long a,int n){
    int i;
    long long ans=1;
    for(i=0;i<30;++i){
        if(n&(1<<i))ans=ans*a%M;
        a=a*a%M;
    }
    return ans;
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    printf("%d",(pow(k,n)*(n-k+1)%M-pow(k-1,n)*(n-k)%M+M)%M);
    return 0;
}
