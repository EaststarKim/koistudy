#include <stdio.h>
#include <algorithm>
int a[100010];
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    std::sort(a+1,a+n+1);
    for(i=n;i;--i)printf("%d ",a[i]);
    return 0;
}
