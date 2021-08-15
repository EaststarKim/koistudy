#include <stdio.h>
int a[100010],t[100010];
long long s[100010],sum,l,r,m,ans;
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;++i)scanf("%d",a+i),sum+=a[i];
    l=1,r=sum/3;
    while(l<=r){
        m=(l+r)/2;
        s[0]=t[0]=0;
        for(i=0;i<n;++i){
            while(s[i]<m)s[i]+=a[t[i]],t[i]=(t[i]+1)%n;
            s[i+1]=s[i]-a[i],t[i+1]=t[i];
        }
        for(i=0;i<n;++i)if(sum-s[i]-s[t[i]]>=m)break;
        if(i<n)ans=m,l=m+1;
        else r=m-1;
    }
    printf("%lld",ans);
    return 0;
}
