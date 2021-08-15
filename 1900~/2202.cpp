#include <stdio.h>
int a[1010][1010];
int main(){
    int i,j,n,m,sr,sc,er,ec,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i){
        scanf("%d%d%d%d%d",&sr,&sc,&er,&ec,&k);
        a[sr][sc]+=k,a[sr][ec+1]-=k;
        a[er+1][sc]-=k,a[er+1][ec+1]+=k;
    }
    for(i=1;i<=n;++i)for(j=1;j<=n;++j)a[i][j]+=a[i][j-1];
    for(i=1;i<=n;++i)for(j=1;j<=n;++j)a[j][i]+=a[j-1][i];
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)printf("%d ",a[i][j]);
        puts("");
    }
    return 0;
}
