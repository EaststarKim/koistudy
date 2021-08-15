#include <stdio.h>
int a[1010],D[1010],ans;
int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        scanf("%d",a+i);
        D[i]=1;
        for(j=1;j<i;++j)if(a[j]+m<=a[i]&&D[j]+1>D[i])D[i]=D[j]+1;
        if(ans<D[i])ans=D[i];
    }
    printf("%d",ans);
    return 0;
}
