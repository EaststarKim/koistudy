#include <stdio.h>
long long a[100010],sum;
int main(){
    int i,n,q,s,e,w;
    scanf("%d%d",&n,&q);
    for(i=1;i<=q;++i){
        scanf("%d%d%d",&s,&e,&w);
        a[s]+=w,a[e+1]-=w;
    }
    for(i=1;i<=n;++i){
        sum+=a[i];
        printf("%lld ",sum);
    }
    return 0;
}
