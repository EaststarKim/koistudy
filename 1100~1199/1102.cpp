#include <stdio.h>
#define M 100000007
long long a[32]={2},t=1;
int main(){
    int i,n,k;
    scanf("%d%d",&n,&k);
    if(n-k<2)printf("%d",n-k+1);
    else{
        n-=k+2;
        for(i=0;i<31;++i){
            if(n&(1<<i))t=(t*a[i])%M;
            a[i+1]=(a[i]*a[i])%M;
        }
        printf("%d",t*(n+5)%M);
    }
    return 0;
}
