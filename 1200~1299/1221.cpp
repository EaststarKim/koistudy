#include <stdio.h>
int main(){
    int i,n,s,e,m,t;
    scanf("%d%d%d",&n,&s,&e);
    m=e;
    for(i=3;i<=n;++i){
        t=e,e=m*2-s,s=m;
        if(m>t)s=m*2-t;
        scanf("%d",&m);
        if(e>m)e=m;
    }
    if(s>e)s=e+1;
    printf("%d",e-s+1);
    return 0;
}
