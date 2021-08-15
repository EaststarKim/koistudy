#include <stdio.h>
#include <string.h>
int t[3010][3010],cnt[3010],ans[3010];
int main(){
    int i,j,k,n,m,a,b,c,d,s;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        ++t[a][c],--t[a][d+1];
        --t[b+1][c],++t[b+1][d+1];
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)t[i][j]+=t[i][j-1];
    }
    for(i=1;i<=n;++i){
        s=0;
        for(j=1;j<=n;++j){
            s+=t[j][i];
            cnt[j]+=t[j][i]=!s;
        }
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)if(cnt[j]==1)break;
        for(k=n;k;--k)if(t[j][k])break;
        ans[j]=k;
        for(j=1;j<=n;++j)if(t[j][k])t[j][k]=0,--cnt[j];
    }
    for(i=1;i<=n;++i)printf("%d\n",ans[i]);
    return 0;
}
