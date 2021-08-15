#include <stdio.h>
int a[100010];
long long ans;
int main(){
    int i,n,x;
    scanf("%d%d",&n,&x);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i<=n;++i){
        if(a[i-1]+a[i]>x)ans+=a[i]+a[i-1]-x,a[i]-=a[i]+a[i-1]-x;
    }
    printf("%lld",ans);
    return 0;
}
