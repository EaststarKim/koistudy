#include <stdio.h>
#include <vector>
using namespace std;
struct data{
    int x,y;
};
vector<data> t[10010];
int a[1010][1010],b[1010][1010];
long long d[1010][1010],ans;
int x[]={-1,0,1,0},y[]={0,1,0,-1};
int main(){
    int i,j,k,n,m,r,c,nr,nc;
    scanf("%d%d",&m,&n);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)scanf("%d",a[i]+j),t[a[i][j]].push_back({i,j});
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)scanf("%d",b[i]+j);
    }
    for(k=1;k<=1e4;++k){
        for(i=0;i<t[k].size();++i){
            r=t[k][i].x,c=t[k][i].y;
            for(j=0;j<4;++j){
                nr=r+x[j],nc=c+y[j];
                if(a[nr][nc]>a[r][c])d[nr][nc]=max(d[nr][nc],d[r][c]+b[r][c]);
            }
        }
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)ans=max(ans,d[i][j]*2+b[i][j]);
    }
    printf("%lld",ans);
    return 0;
}
