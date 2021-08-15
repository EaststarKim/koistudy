#include <stdio.h>
int a[1010][1010];
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)scanf("%1d",a[i]+j);
    }
    for(k=1;k<=n;++k){
        for(i=1;i<=n;++i)if(a[i][k]){
            for(j=1;j<=n;++j)if(a[k][j]&&i!=j)a[i][j]=1;
        }
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)printf("%d ",a[i][j]);
        puts("");
    }
    return 0;
}
