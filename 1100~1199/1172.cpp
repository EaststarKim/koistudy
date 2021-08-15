#include <stdio.h>
int a[21],D[21]={1};
int main(){
    int i,n,k,t;
    scanf("%d%d",&n,&k);
    for(i=1;i<=k;++i)scanf("%d",&t),a[t]=1;
    for(i=1;i<=n;++i)if(!a[i]){
        D[i]=D[i-1];
        if(i>1)D[i]+=D[i-2];
    }
    printf("%d",D[n]);
    return 0;
}
