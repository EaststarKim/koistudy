#include <stdio.h>
int a[1010][1010];
int main(){
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)scanf("%1d",a[i]+j);
    }
    for(i=1;i<=m;++i){
        for(j=1;j<=n;++j)if(a[j][i])a[j][i]+=a[j-1][i];
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)printf("%d ",a[i][j]);
        puts("");
    }
    return 0;
}
