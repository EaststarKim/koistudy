#include <stdio.h>
long long a[1000010],ans;
int p[1000010];
int main(){
    int i,n,t,m;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d%d",&t,&m);
        if(m)a[i]=a[t]+m,p[i]=t;
        else a[i]=a[p[t]],p[i]=p[p[t]];
        ans+=a[i];
    }
    printf("%lld",ans);
    return 0;
}
