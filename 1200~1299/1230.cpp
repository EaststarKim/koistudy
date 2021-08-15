#include <stdio.h>
#include <algorithm>
using namespace std;
long long a[110],b[110],ans;
int main(){
    int i,j,k,n,cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;++i)scanf("%lld",a+i);
    for(i=49;i>=0;--i){
        for(j=cnt;j<n;++j)if(a[j]&(1ll<<i)){
            swap(a[j],a[cnt]);
            b[cnt]=1ll<<i;
            for(k=cnt+1;k<n;++k)if(a[k]&b[cnt])a[k]^=a[cnt];
            ++cnt;
        }
    }
    for(i=cnt-1;i>0;--i){
        for(j=i-1;j>=0;--j)if(a[j]&b[i])a[j]^=a[i];
    }
    for(i=1;i<cnt;++i)a[0]^=a[i];
    for(i=1;i<n;++i)a[i]^=a[0];
    for(i=0;i<n;++i)ans+=a[i];
    printf("%lld",ans);
    return 0;
}
