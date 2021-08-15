#include <stdio.h>
int a[110],c[110],D[110],cnt[110];
int main(){
    int i,j,k,n,l;
    scanf("%d%d",&k,&n);
    for(i=1;i<=n+1;++i)scanf("%d",a+i);
    for(i=1;i<=n;++i)scanf("%d",c+i);
    for(i=1;i<=n+1;++i){
        D[i]=1<<30,l=0;
        for(j=i-1;j>=0&&l+a[j+1]<=k;--j){
            l+=a[j+1];
            if(D[i]>D[j]+c[i]||(D[i]==D[j]+c[i]&&cnt[i]>cnt[j]+1)){
                D[i]=D[j]+c[i];
                cnt[i]=cnt[j]+1;
            }
        }
    }
    printf("%d %d",D[n+1],cnt[n+1]-1);
    return 0;
}
