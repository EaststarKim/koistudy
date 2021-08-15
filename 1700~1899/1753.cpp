#include <stdio.h>
int a[10010];
int main(){
    int i,n,q,s,t,ans;
    scanf("%d%d",&n,&q);
    ans=n;
    for(;q--;){
        scanf("%d%d",&s,&t);
        for(i=s;i<=n;i+=t)if(!a[i])--ans,a[i]=1;
    }
    printf("%d",ans);
    return 0;
}
