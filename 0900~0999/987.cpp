#include <stdio.h>
struct data{
    int r,c;
}q[100010];
int a[110][110],d[110][110],f,r=1;
int dr[]={-1,0,1,0},dc[]={0,1,0,-1};
int main()
{
    int i,j,n,h,nr,nc;
    scanf("%d%d",&n,&h);
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)scanf("%d",a[i]+j);
    }
    q[1].r=q[1].c=1;
    d[1][1]=h-a[1][1];
    while(f<r){
        ++f;
        for(i=0;i<4;++i){
            nr=q[f].r+dr[i];
            nc=q[f].c+dc[i];
            if(nr<1||nr>n||nc<1||nc>n||d[nr][nc]>=d[q[f].r][q[f].c]-a[nr][nc])continue;
            d[nr][nc]=d[q[f].r][q[f].c]-a[nr][nc];
            q[++r].r=nr;
            q[r].c=nc;
        }
    }
    if(d[n][n]<1)puts("-1");
    else printf("%d",d[n][n]);
    return 0;
}
