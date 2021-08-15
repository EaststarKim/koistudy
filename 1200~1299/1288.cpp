#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int r,c;
}a[16],q[910];
int chk[31][31],d[16][16],D[1<<15][15],n,m,ans=1e4;
int x[]={-3,-2,2,3,3,2,-2,-3},y[]={2,3,3,2,-2,-3,-3,-2};
void bfs(int p){
    int i,j,f=0,r=1,nr,nc;
    for(i=1;i<=n;++i)for(j=1;j<=n;++j)chk[i][j]=0;
    q[1]=a[p],chk[a[p].r][a[p].c]=1;
    while(f<r){
        ++f;
        for(i=0;i<8;++i){
            nr=q[f].r+x[i],nc=q[f].c+y[i];
            if(nr<1||nr>n||nc<1||nc>n||chk[nr][nc])continue;
            chk[nr][nc]=chk[q[f].r][q[f].c]+1;
            q[++r]={nr,nc};
        }
    }
    for(i=0;i<=m;++i)d[p][i]=chk[a[i].r][a[i].c]-1;
    D[1<<p][p]=chk[1][1];
}
int main(){
    int i,j,k,l,nr,nc;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;++i)scanf("%d%d",&a[i].r,&a[i].c);
    a[m]={n,n};
    for(i=0;i<m;++i)bfs(i);
    for(i=0;i<m;++i)for(j=1;j<=m;++j)if(d[i][j]<1)d[i][j]=1e4;
    for(i=1;i<(1<<m);++i)for(j=0;j<m;++j)if(D[i][j]<1)D[i][j]=1e4;
    for(i=1;i<m;++i){
        for(j=1;j<(1<<m);++j)if(__builtin_popcount(j)==i){
            for(k=0;k<m;++k)if(D[j][k]<1e4){
                for(l=0;l<m;++l)D[j|(1<<l)][l]=min(D[j|(1<<l)][l],D[j][k]+d[k][l]);
            }
        }
    }
    for(i=0;i<m;++i)ans=min(ans,D[(1<<m)-1][i]+d[i][m]);
    if(ans==1e4)ans=0;
    printf("%d",ans-1);
    return 0;
}
