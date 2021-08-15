#include <stdio.h>
#include <algorithm>
int a[1010][1010],b[1010][1010],q[2][1000010],f,r=1;
int dr[]={-1,0,1,0},dc[]={0,1,0,-1};
int main()
{
    int i,j,n,m,nr,nc,ro,co;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)scanf("%d",&a[i][j]),b[i][j]=1000001;
    }
    b[1][1]=1;
    q[0][1]=q[1][1]=1;
    while(f<r)
    {
        ro=q[0][++f];
        co=q[1][f];
        if(ro==n&&co==m)break;
        for(i=0;i<4;++i)
        {
            nr=ro+dr[i];
            nc=co+dc[i];
            if(nr<1||nr>n||nc<1||nc>m||b[nr][nc]<=b[ro][co]+1)continue;
            if(abs(a[nr][nc]-a[ro][co])>1)continue;
            b[nr][nc]=b[ro][co]+1;
            q[0][++r]=nr;
            q[1][r]=nc;
        }
    }
    if(b[n][m]<1000001)printf("%d",b[n][m]);
    else printf("0");
    return 0;
}
