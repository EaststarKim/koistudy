#include <stdio.h>
#include <string.h>
int a[101][101],b[101][101],chk[101][101],n,m,t,s;
int dr[]={0,1,0,-1},dc[]={1,0,-1,0};
void ff(int r,int c)
{
    chk[r][c]=1;
    int i, nr, nc;
    for(i=0;i<4;++i){
        nr=r+dr[i],nc=c+dc[i];
        if(nr<1 || nr>n || nc<1 || nc>m || chk[nr][nc])continue;
        if(a[nr][nc])
        {
            ++b[nr][nc];
            if(b[nr][nc]>1)chk[nr][nc]=1;
        }
        else ff(nr,nc);
    }
}
int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j])++s;
        }
    }
    for(t=0;;++t)
    {
        if(s==0)break;
        ff(1,1);
        for(i=1;i<=n;++i){
            for(j=1;j<=m;++j){
                if(!a[i][j]&&!chk[i][j])ff(i,j);
            }
        }
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
            {
                if(b[i][j]>1)
                {
                    a[i][j]=0;
                    --s;
                }
            }
        }
        memset(b,0,sizeof(b));
        memset(chk,0,sizeof(chk));
    }
    printf("%d",t);
    return 0;
}
