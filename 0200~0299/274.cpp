#include <stdio.h>
int a[70];
int main(){
    int i,j,n,b,d,t=1;
    scanf("%d%d%d",&n,&b,&d);
    b=1<<b;
    for(i=1;i<b;++i){
        for(j=t;j;--j)if(__builtin_popcount(i^a[j])<d)break;
        if(!j)a[++t]=i;
        if(t==n)break;
    }
    for(i=1;i<=n;++i)printf("%d ",a[i]);
    return 0;
}
