#include <stdio.h>
int a[10010];
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i),printf("%d ",a[i]-a[i-1]);
    return 0;
}
