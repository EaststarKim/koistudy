#include <stdio.h>
struct data{
    int r,c;
}q[1000010];
int a[1010][1010],chk[1010][1010],n,m,cnt;
int dr[]={-1,0,1,0},dc[]={0,1,0,-1};
void bfs(int ro,int co){
    int i,nr,nc,f=0,r=1;
    chk[ro][co]=1;
    q[1].r=ro,q[1].c=co;
    while(f<r){
        ro=q[++f].r,co=q[f].c;
        for(i=0;i<4;++i){
            nr=ro+dr[i],nc=co+dc[i];
            if(nr<1||nr>n||nc<1||nc>m||!a[nr][nc]||chk[nr][nc])continue;
            q[++r].r=nr,q[r].c=nc,chk[nr][nc]=1;
        }
    }
}
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)scanf("%1d",a[i]+j);
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)if(a[i][j]&&!chk[i][j])++cnt,bfs(i,j);
    }
    printf("%d",cnt);
    return 0;
}
