#include <stdio.h>
int a[1010],ans;
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",a+i);
        for(j=1;j<i;++j)ans+=(a[j]>a[i]);
    }
    printf("%d",ans);
    return 0;
}
