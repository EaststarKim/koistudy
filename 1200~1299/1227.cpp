#include <stdio.h>
long long ans;
int main(){
    int i,n,s,c,y,mc=1e9;
    scanf("%d%d",&n,&s);
    for(i=1;i<=n;++i){
        scanf("%d%d",&c,&y);
        if(mc>c)mc=c;
        ans+=mc*y;
        mc+=s;
    }
    printf("%lld",ans);
    return 0;
}
