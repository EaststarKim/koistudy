#include <stdio.h>
int main(){
    int i,j,n,m,t,cnt=0,ans=0;
    scanf("%d%d",&n,&m);
    for(i=n;i<=m;++i){
        for(t=0,j=i;j;j/=10)t+=j%10;
        if(i%t)cnt=0;
        else ++cnt;
        if(ans<cnt)ans=cnt;
    }
    printf("%d",ans);
    return 0;
}
