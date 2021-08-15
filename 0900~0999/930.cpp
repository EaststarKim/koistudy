#include <stdio.h>
int a[260][260];
int main(){
    int i,j,k,n,cnt;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)scanf("%1d",a[i]+j),a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    }
    for(i=2;i<=n;++i){
        cnt=0;
        for(j=i;j<=n;++j){
            for(k=i;k<=n;++k)cnt+=(a[j][k]-a[j-i][k]-a[j][k-i]+a[j-i][k-i]==i*i);
        }
        if(cnt)printf("%d %d\n",i,cnt);
    }
    return 0;
}
