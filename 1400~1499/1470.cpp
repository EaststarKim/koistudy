#include <stdio.h>
char a[1010][1010];
int chk[1010][1010],s[1000010],n,m,t;
int x[]={-1,0,1,0},y[]={0,1,0,-1};
void ff(int r,int c){
    int i,nr,nc;
    chk[r][c]=t;
    for(i=0;i<4;++i){
        nr=r+x[i],nc=c+y[i];
        if(a[nr][nc]=='*')++s[t];
        else if(!chk[nr][nc])ff(nr,nc);
    }
}
int main(){
    int i,j,k;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;++i)scanf("%s",a[i]+1);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)if(a[i][j]=='.'&&!chk[i][j]){
            ++t;
            ff(i,j);
        }
    }
    for(;k--;){
        scanf("%d%d",&i,&j);
        printf("%d\n",s[chk[i][j]]);
    }
    return 0;
}
