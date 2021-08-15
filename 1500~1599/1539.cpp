#include <stdio.h>
int p[3000]={0,2},t=1;
int main(){
    int i,j,n,k,mx=0,mi=1;
    for(i=3;i<2e4;i+=2){
        for(j=1;j<=t;++j)if(i%p[j]==0)break;
        if(j>t)p[++t]=i;
    }
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&k);
        for(j=1;j<=t&&p[j]<=k;++j)if(k%p[j]==0){
            if(mx<j)mx=j,mi=k;
        }
    }
    printf("%d",mi);
    return 0;
}
