#include <stdio.h>
int a[361],mx;
int main(){
    int i,n,k,cnt;
    scanf("%d%d",&k,&n);
    for(i=1;i<=n;++i){
        scanf("%d",a+i);
        if(a[i-1]==a[i])++cnt;
        else cnt=1;
        if(mx<cnt)mx=cnt;
    }
    printf("%d",mx);
    return 0;
}
