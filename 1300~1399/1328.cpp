#include <stdio.h>
long long D[100010]={1};
int main(){
    int i,j,n,k,s=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&k);
        s+=k;
        for(j=s;j>=k;--j)D[j]+=D[j-k];
    }
    if(s%2)puts("0");
    else printf("%lld",D[s/2]/2);
    return 0;
}
