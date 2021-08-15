#include <stdio.h>
int a[1010][1010];
int main(){
    int i,j,n,m,q,x,y,z,w,k;
    scanf("%d%d%d",&n,&m,&q);
    for(;q--;){
        scanf("%d%d%d%d%d",&x,&y,&z,&w,&k);
        a[x][y]+=k,a[x][w+1]-=k;
        a[z+1][y]-=k,a[z+1][w+1]+=k;
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1],printf("%d ",a[i][j]);
        puts("");
    }
    return 0;
}
