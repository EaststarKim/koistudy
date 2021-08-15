#include <stdio.h>
int a[1010],b[1010],chk[1010];
int main(){
    int i,j,r,k,n,s,t,p;
    long long ans=0,sum=0;
    scanf("%d%d%d",&r,&k,&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=j=1;i<=n;++i){
        if(chk[j])break;
        chk[j]=i;
        for(s=0,t=j;s+a[j]<=k;){
            s+=a[j],j=j>n?1:j+1;
            if(j==t)break;
        }
        b[i]=s;
    }
    p=i-chk[j];
    for(i=1;i<chk[j]&&r;++i,--r)ans+=b[i];
    for(i=0;i<p;++i)sum+=b[chk[j]+i];
    ans+=r/p*sum;
    r%=p;
    for(i=0;i<r;++i)ans+=b[chk[j]+i];
    printf("%lld",ans);
    return 0;
}
