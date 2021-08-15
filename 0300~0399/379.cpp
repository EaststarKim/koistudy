#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int a[100010],b[100010],sum[2];
int main(){
    int i,j,k,l,n,x,y,s,t;
    long long ans=0;
    scanf("%d%d",&l,&n);
    for(i=1;i<=n;++i){
        scanf("%d%d",&x,&y);
        a[i]=x+y,b[i]=x-y;
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    s=t=1;
    for(i=2;i<=n;++i){
        if(a[s]!=a[i])a[++s]=a[i];
        if(b[t]!=b[i])b[++t]=b[i];
    }
    for(i=1;i<=t;++i)b[i]=abs(b[i]);
    sort(b+1,b+t+1);
    for(i=1;i<=s;++i)ans+=(a[i]<l?a[i]+1:l*2-a[i]-1);
    for(i=1;i<=t;++i)ans+=l-b[i];
    for(i=j=1,k=t;i<=s;++i){
        for(;j<=t&&b[j]<=a[i];++j)++sum[b[j]%2];
        for(;k&&a[i]+b[k]>l*2-2;--k)--sum[b[k]%2];
        ans-=sum[a[i]%2];
        for(;k&&a[i]+b[k]>l*2-3;--k)--sum[b[k]%2];
    }
    printf("%lld",ans);
    return 0;
}
