#include <stdio.h>
int a[21][21],n;
int dr[]={0,1,0,-1},dc[]={1,0,-1,0};
int main()
{
    int i,j,r=2,c=2,p=0,nr,nc;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)scanf("%d",a[i]+j);
    }
    for(;;){
        if(a[r][c]==2){
            a[r][c]=9;
            break;
        }
        a[r][c]=9;
        nr=r+dr[(p+3)%4],nc=c+dc[(p+3)%4];
        if(a[nr][nc]==1){
            nr=r+dr[p],nc=c+dc[p];
            if(a[nr][nc]==1)p=(p+1)%4;
            else r=nr,c=nc;
        }
        else{
            p=(p+3)%4;
            r=r+dr[p],c=c+dc[p];
        }
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)printf("%d ",a[i][j]);
        puts("");
    }
    return 0;
}
