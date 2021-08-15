#include <stdio.h>
int main(){
    int i,tc,a,b,c,s,t;
    scanf("%d",&tc);
    for(i=1;i<=tc;++i){
        scanf("%d%d%d",&a,&b,&c);
        s=0,t=b;
        for(;a--;)s+=(t+c-1)/c,t=t%c+b;
        printf("Case #%d: %d\n",i,s);
    }
    return 0;
}
