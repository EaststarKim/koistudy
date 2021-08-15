#include <stdio.h>
int a[2010];
long long s[5010],D[5010],ans;
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i<=n;++i){
        for(j=1;j<i;++j){
            if(a[i]>a[j])++s[a[i]-a[j]];
            else ++s[a[j]-a[i]];
        }
    }
    for(i=1;i<4999;++i){
        for(j=1;j<i;++j)D[i]+=s[j]*s[i-j];
    }
    for(i=4999;i;--i)s[i]+=s[i+1];
    for(i=1;i<4999;++i)ans+=D[i]*s[i+1];
    printf("%lld",ans);
    return 0;
}
