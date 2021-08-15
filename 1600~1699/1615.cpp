#include <stdio.h>
int a[1010][1010];
int main(){
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            scanf("%d",a[i]+j);
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            printf("%d ",a[i][j]);
        }
        puts("");
    }
    return 0;
}
