#include <stdio.h>
#include <algorithm>
using namespace std;
long long D[300010],a,b,c;
int main(){
    int i,j,k;
    scanf("%d%d%d%d",&a,&b,&c,&k);
    for(i=2;i<=k;++i)D[i]=1e18;
    D[1]=a;
    for(i=1;i<k;++i){
        D[i+1]=min(D[i+1],D[i]+a);
        for(j=2;i*j<=k;++j)D[i*j]=min(D[i*j],D[i]+b+(j-1)*c);
    }
    printf("%lld",D[k]);
    return 0;
}
