#include <stdio.h>
int a[100010],t,ans;
int main(){
    int i,n,k;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&k);
        while(t&&a[t]<k)--t,++ans;
        a[++t]=k;
    }
    printf("%d",ans);
    return 0;
}
