#include <stdio.h>
int a[51],D[2000010];
int main(){
    int i,j,n,k;
    scanf("%d%d",&k,&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i<=2e6;++i){
        D[i]=1e3;
        for(j=1;j<=n;++j)if(a[j]<=i&&D[i]>D[i-a[j]]+1)D[i]=D[i-a[j]]+1;
        if(D[i]>k)break;
    }
    printf("%d",i-1);
    return 0;
}
