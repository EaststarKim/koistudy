#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int x,y,c;
    bool operator<(const data&r)const{
        return c<r.c;
    }
}a[2000];
int mat[50][50],D[50][50],p,ans;
int dr[]={-1,-1,-1,0,1,1,1,0},dc[]={-1,0,1,1,1,0,-1,-1};
int main()
{
    int i,j,n,r,c,nr,nc;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j){
            scanf("%d",mat[i]+j);
            a[p].x=i;
            a[p].y=j;
            a[p++].c=mat[i][j];
        }
    }
    sort(a,a+n*n);
    for(i=0;i<p;++i){
        r=a[i].x;
        c=a[i].y;
        D[r][c]=1;
        for(j=0;j<8;++j){
            nr=r+dr[j];
            nc=c+dc[j];
            if(mat[nr][nc]==a[i].c-1)D[r][c]=max(D[r][c],D[nr][nc]+1);
        }
        ans=max(ans,D[r][c]);
    }
    printf("%d",ans);
    return 0;
}
