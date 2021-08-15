#include <stdio.h>
int D[21]={1};
int main(){
    int i,j,n,k,x=0,y;
    scanf("%d%d",&n,&k);
    for(;k--;){
        scanf("%d",&y);
        for(i=x;i<y;++i){
            for(j=1;j<7&&i+j<=y;++j)D[i+j]+=D[i];
        }
        x=y;
    }
    for(i=x;i<n;++i){
        for(j=1;j<7&&i+j<=n;++j)D[i+j]+=D[i];
    }
    printf("%d",D[n]);
    return 0;
}
