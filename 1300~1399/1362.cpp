#include <stdio.h>
int a[110];
int main(){
    int i,t,n,ans;
    scanf("%d",&t);
    for(;t--;){
        scanf("%d",&n);
        a[n+1]=ans=0;
        for(i=1;i<=n;++i)scanf("%d",a+i);
        for(i=1;i<=n;++i)ans+=(a[i]|(a[i-1]&a[i+1]));
        printf("%d\n",ans);
    }
    return 0;
}
