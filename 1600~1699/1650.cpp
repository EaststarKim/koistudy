#include <stdio.h>
#include <algorithm>
using namespace std;
long long a[100010],D[100010];
int main(){
    int i,n,k;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&k);
        ++a[k];
    }
    D[1]=a[1];
    for(i=2;i<=100000;++i)D[i]=max(D[i-1],D[i-2]+a[i]*i);
    printf("%lld",D[100000]);
    return 0;
}
