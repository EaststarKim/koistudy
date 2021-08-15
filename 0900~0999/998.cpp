#include <stdio.h>
#include <stdlib.h>
int a[110],sum;
int main(){
    int i,n,m,s,e,c;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i)scanf("%d%d%d",&s,&e,&c),a[s]+=c,a[e]-=c;
    for(i=1;i<=n;++i)sum+=abs(a[i]);
    printf("%d",sum/2);
    return 0;
}
