#include <stdio.h>
int a[100010],ans;
int main(){
    int i,j,n,k;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;++i)scanf("%d",a+i),a[i]+=a[i-1];
    for(i=1,j=0;i<=n;++i){
        for(;;++j)if(a[i]-a[j]<=k)break;
        if(a[i]-a[j]==k)++ans;
    }
    printf("%d",ans);
    return 0;
}
