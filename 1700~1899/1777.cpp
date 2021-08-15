#include <stdio.h>
int a[1000010];
int main(){
    int i,n,k;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    long long l=0,r=2e9,m,ans,s;
    while(l<=r){
        m=(l+r)/2;
        for(i=1,s=0;i<=n;++i)s+=(a[i]>m?a[i]-m:0);
        if(s<k)r=m-1;
        else l=m+1,ans=m;
    }
    printf("%d",ans);
    return 0;
}
