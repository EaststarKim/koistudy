#include <stdio.h>
int a[6][6],vis[6][6],chk[6];
int b[6][4]={{1,2,3,4},{5,2,0,4},{1,5,3,0},{0,2,5,4},{1,0,3,5},{3,2,1,4}};
int d[6][6]={{0,0,1,2,3,0},{2,0,1,0,3,0},{3,0,0,2,0,1},{0,0,1,0,3,2},{1,0,0,2,0,3},{0,2,1,0,3,0}};
int e[]={5,3,4,1,2,0};
int x[]={-1,0,1,0},y[]={0,1,0,-1};
int f(int r,int c,int t=0,int dir=1){
    if(chk[t])return 0;
    chk[t]=vis[r][c]=1;
    int i,nr,nc;
    for(i=0;i<4;++i){
        nr=r+x[i],nc=c+y[i];
        if(nr<0||nr>5||nc<0||nc>5||!a[nr][nc]||vis[nr][nc])continue;
        if(!f(nr,nc,b[t][(i+d[t][dir])%4],!i?e[t]:(i%2?dir:t)))return 0;
    }
    return 1;
}
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(;n--;){
        for(i=0;i<6;++i){
            for(j=0;j<6;++j)scanf("%d",a[i]+j),vis[i][j]=0;
            chk[i]=0;
        }
        for(i=0;i<6;++i){
            for(j=0;j<6;++j)if(a[i][j]){
                puts(f(i,j)?"yes":"no");
                break;
            }
            if(j<6)break;
        }
    }
    return 0;
}
