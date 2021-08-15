#include <stdio.h>
int a[110],b[110][110],d[110][10010];
int main(){
    int i,j,k,n,m,t,mn,mi;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        scanf("%d",a+i);
        for(j=1;j<=n;++j)scanf("%d",&t),b[i][t]=j;
        d[i][1]=i,d[i%n+1][0]=i;
    }
    for(i=2;i<=m;++i){
        for(j=1;j<=n;++j){
            mn=101;
            for(k=i-1;k>=i-a[j]&&k>=0;--k)if(b[j][d[j%n+1][k]]<mn)mn=b[j][d[j%n+1][k]],mi=d[j%n+1][k];
            d[j][i]=mi;
        }
    }
    printf("%d",d[1][m]);
    return 0;
}
