#include <stdio.h>
#include <algorithm>
#define SZ 16
using namespace std;
int s[SZ][SZ],a[SZ][SZ],b[SZ][SZ],c[SZ][SZ],d[SZ][SZ],e[SZ][SZ],f[SZ][SZ],ans;
int S(int x1,int y1,int x2,int y2){return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];}
int main(){
    int i,j,n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            scanf("%d",s[i]+j);
            s[i][j]=s[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }
    for(i=k;i<=n;++i){
        for(j=k;j<=m;++j)a[i][j]=max(S(i-k+1,j-k+1,i,j),max(a[i-1][j],a[i][j-1]));
        for(j=m-k+1;j>0;--j)b[i][j]=max(S(i-k+1,j,i,j+k-1),max(b[i][j+1],b[i-1][j]));
    }
    for(i=n-k+1;i>0;--i){
        for(j=k;j<=m;++j)c[i][j]=max(S(i,j-k+1,i+k-1,j),max(c[i][j-1],c[i+1][j]));
        for(j=m-k+1;j>0;--j)d[i][j]=max(S(i,j,i+k-1,j+k-1),max(d[i][j+1],d[i+1][j]));
    }
    for(i=k+1;i<=n-k*2+1;++i){
        for(j=k;j<=m;++j)e[i][i]=max(e[i][i],S(i,j-k+1,i+k-1,j));
        for(j=k+1;j<i;++j)e[j][i]=max(e[j][i-1],e[i][i]);
    }
    for(i=k+1;i<=m-k*2+1;++i){
        for(j=k;j<=m;++j)f[i][i]=max(f[i][i],S(j-k+1,i,j,i+k-1));
        for(j=k+1;j<i;++j)f[j][i]=max(f[j][i-1],f[i][i]);
    }
    for(i=k;i<=n-k+1;++i)for(j=k;j<=m-k+1;++j)ans=max(ans,max(a[n][j]+b[i][j+1]+d[i+1][j+1],max(b[i][1]+c[i+1][j]+d[i+1][j+1],max(c[i+1][m]+a[i][j]+b[i][j+1],d[1][j+1]+a[i][j]+c[i+1][j]))));
    for(i=k+1;i<=n-k*2+1;++i)for(j=i;j<=n-k*2+1;++j)ans=max(ans,a[i-1][m]+e[i][j]+c[j+k][m]);
    for(i=k+1;i<=m-k*2+1;++i)for(j=i;j<=m-k*2+1;++j)ans=max(ans,a[n][i-1]+f[i][j]+b[n][j+k]);
    printf("%d",ans);
    return 0;
}
