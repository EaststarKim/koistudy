#include <stdio.h>
long long a[100010]={1,1};
int main(){
    int i,n,k,ans=0;
    scanf("%d%d",&n,&k);
    for(i=2;i<n;++i)a[i]=a[i-1]*2%100000007;
    for(i=k;i<=n;++i)ans=(ans+a[i-k]*a[n-i])%100000007;
    printf("%d",ans);
    return 0;
}
