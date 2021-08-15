#include <stdio.h>
int a[1010],D[1010]={1};
int main(){
    int i,t,n,m,k,ans;
    scanf("%d",&t);
    for(;t--;){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;++i)a[i]=D[i]=0;
        for(i=1;i<=m;++i)scanf("%d",&k),a[k]=1;
        ans=0;
        for(i=1;i<=n;++i){
            D[i]=D[i-1]+(i>1?D[i-2]:0)+(i>2?D[i-3]:0);
            if(a[i])ans+=D[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
