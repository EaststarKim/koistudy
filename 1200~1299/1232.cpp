#include <stdio.h>
long long a[1<<21],ans;
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%lld",a+i);
    for(i=n;i;--i)a[i]+=a[i*2]+a[i*2+1];
    for(i=1;i<=n;++i)a[i*2]+=a[i],a[i*2+1]+=a[i];
    for(i=n;i>n/2;--i)if(ans<a[i])ans=a[i];
    printf("%lld",ans);
    return 0;
}
