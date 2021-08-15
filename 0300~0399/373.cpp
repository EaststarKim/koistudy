#include <stdio.h>
int a[1010][1010],D[1010][1010];
int main(){
    int i,j,n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    D[1][1]=k-1;
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            scanf("%d",a[i]+j);
            int t=a[i][j]?(D[i][j]+1)/2:D[i][j]/2;
            D[i][j+1]+=t;
            D[i+1][j]+=D[i][j]-t;
            a[i][j]=(a[i][j]+D[i][j])%2;
        }
    }
    for(i=j=1;i<=n&&j<=m;){
        if(a[i][j])++j;
        else ++i;
    }
    printf("%d %d",i,j);
    return 0;
}
