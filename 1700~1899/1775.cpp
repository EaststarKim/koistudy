#include <stdio.h>
int a[51];
long long D[51][2510],ans;
int main(){
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    D[0][0]=1;
    for(i=1;i<=n;++i){
        for(j=i;j;--j){
            for(k=a[i];k<2501;++k)D[j][k]+=D[j-1][k-a[i]];
        }
    }
    for(i=1;i<=n;++i)ans+=D[i][m*i];
    printf("%lld",ans);
    return 0;
}
