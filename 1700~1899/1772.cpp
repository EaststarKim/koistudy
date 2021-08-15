#include <stdio.h>
#define M 1000000007
int a[100010],ans;
int main(){
    int i,j,n,s;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=0;i<17;++i){
        for(j=1,s=0;j<=n;++j)if(a[j]&(1<<i))++s;
        ans=(ans+(long long)s*(n-s)*2)%M;
    }
    printf("%d",ans);
    return 0;
}
