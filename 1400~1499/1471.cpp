#include <stdio.h>
#include <algorithm>
using namespace std;
int a[20010];
long long D[20010];
int main(){
    int i,j,n,m,k,mx,mn;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i<=n;++i){
        D[i]=1e18;
        mn=mx=a[i];
        for(j=i-1;j>=max(0,i-m);--j){
            D[i]=min(D[i],D[j]+k+(long long)(i-j)*(mx-mn));
            mx=max(mx,a[j]);
            mn=min(mn,a[j]);
        }
    }
    printf("%lld",D[n]);
    return 0;
}
