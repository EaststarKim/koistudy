#include <stdio.h>
#include <algorithm>
using namespace std;
int a[110];
long long D[110];
int main(){
    int i,j,k,n,mx,mn;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",a+i);
        mx=mn=a[i];
        for(j=i-1;j>0;--j){
            mx=max(mx,a[j]),mn=min(mn,a[j]);
            for(k=0;k<j;++k)D[i]=max(D[i],D[k]+mx-mn);
        }
    }
    printf("%lld",D[n]);
    return 0;
}
