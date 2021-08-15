#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int x,y,z;
}q[10000010];
int a[110][110],D[110][110][9],f,r=1;
int x[]={-1,0,1,0},y[]={0,1,0,-1};
int main(){
    int i,j,k,l,n,s,e,nr,nc;
    scanf("%d%d%d",&n,&s,&e);
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)scanf("%d",a[i]+j);
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j){
            for(k=0;k<7;++k)D[i][j][k]=1e9;
        }
    }
    D[1][1][s]=0;
    q[1]={1,1,s};
    while(f<r){
        i=q[++f].x,j=q[f].y,k=q[f].z;
        for(l=0;l<4;++l){
            nr=i+x[l],nc=j+y[l];
            if(nr<1||nr>n||nc<1||nc>n||a[nr][nc]||D[nr][nc][(k+1)%7]<=D[i][j][k]+1)continue;
            D[nr][nc][(k+1)%7]=D[i][j][k]+1;
            q[++r]={nr,nc,(k+1)%7};
        }
    }
    printf("%d",D[n][n][e]==1e9?-1:D[n][n][e]);
    return 0;
}
