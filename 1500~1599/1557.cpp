#include <stdio.h>
int a[10010],s,ans;
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i),s+=a[i];
    if(s%n){
        puts("-1");
        return 0;
    }
    s/=n;
    for(i=1;i<=n;++i)if(a[i]>s)ans+=a[i]-s;
    printf("%d",ans);
    return 0;
}
