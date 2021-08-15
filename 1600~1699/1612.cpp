#include <stdio.h>
#include <queue>
using namespace std;
struct data{
    int i,j,d;
    bool operator<(const data&r)const{
        return d>r.d;
    }
};
int a[110][110],D[110][110];
int x[]={-1,0,1,0},y[]={0,1,0,-1};
priority_queue<data> q;
int main(){
    int i,j,n,m,nr,nc;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)scanf("%d",a[i]+j),D[i][j]=1e9;
    }
    q.push({1,1,D[1][1]=a[1][1]});
    while(!q.empty()){
        data t=q.top();
        q.pop();
        if(t.d!=D[t.i][t.j])continue;
        for(i=0;i<4;++i){
            nr=t.i+x[i],nc=t.j+y[i];
            if(nr<1||nr>n||nc<1||nc>m||D[nr][nc]<=t.d+a[nr][nc])continue;
            q.push({nr,nc,D[nr][nc]=t.d+a[nr][nc]});
        }
    }
    printf("%d",D[n][m]);
    return 0;
}
