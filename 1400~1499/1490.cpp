#include <stdio.h>
#define M 1000000007
int a[510],b[510];
int D[510];
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d%d",a+i,b+i);
    D[0]=1;
    for(i=1;i<=n;++i){
        for(j=0;j<i;++j)if(a[j]<a[i])D[i]=(D[i]+D[j])%M;
    }
    long long ans=0;
    for(i=1;i<=n;++i)ans=(ans+D[i])%M;
    printf("%d",ans);
    return 0;
}
