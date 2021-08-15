#include <stdio.h>
int a[10000010],cnt[10000010];
long long ans;
int main(){
    int i,n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;++i){
        scanf("%d",a+i);
        ans+=cnt[a[i]];
        ++cnt[a[i]];
        if(i>k)--cnt[a[i-k]];
    }
    printf("%lld",ans);
    return 0;
}
