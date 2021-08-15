#include <stdio.h>
long long a[10010];
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%lld",a+i),a[i]+=a[i-1],printf("%lld ",a[i]);
    return 0;
}
