#include <stdio.h>
int p[10000]={2},chk[100000]={0,0,1},t,ans;
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=3;i<n;i+=2){
        for(j=1;j<=t&&p[j]*p[j]<=i;++j)if(i%p[j]==0)break;
        if(j>t||p[j]*p[j]>i)chk[p[++t]=i]=1;
    }
    for(i=0;i<=t;++i){
        for(j=0;j<=t&&p[j]<=(n-p[i])/2;++j)ans+=chk[n-p[i]-p[j]];
    }
    printf("%d",ans);
    return 0;
}
