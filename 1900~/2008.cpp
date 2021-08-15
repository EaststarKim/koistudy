#include <stdio.h>
int a[110][110],chk[110][110],flag,cnt;
int x[]={-1,-1,0,1,1,1,0,-1},y[]={0,1,1,1,0,-1,-1,-1};
void ff(int r,int c){
    int i,nr,nc;
    chk[r][c]=1;
    for(i=0;i<8;++i){
        nr=r+x[i],nc=c+y[i];
        if(a[nr][nc]>a[r][c])flag=1;
        if(a[nr][nc]==a[r][c]&&!chk[nr][nc])ff(nr,nc);
    }
}
int main(){
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)for(j=1;j<=m;++j)scanf("%d",a[i]+j);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)if(a[i][j]&&!chk[i][j]){
            flag=0;
            ff(i,j);
            if(!flag)++cnt;
        }
    }
    printf("%d",cnt);
    return 0;
}
