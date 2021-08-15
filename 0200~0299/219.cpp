#include <stdio.h>   
#include <string.h>   
int a[1010][1010],b[1010][1010],q[2][1000010],mn=2000010,n,m;   
int xx[]={-1,0,1,0},yy[]={0,1,0,-1};   
int f[3][1000010],p;   
void BFS()   
{   
    int k,nr,nc,ro,co,f=0,r=1;   
    while(f<r)   
    {   
        ro=q[0][++f];   
        co=q[1][f];   
        for(k=0;k<4;++k)   
        {   
            nr=ro+xx[k];   
            nc=co+yy[k];   
            if(nr<1||nr>n||nc<1||nc>m||a[nr][nc]==1||b[nr][nc]<b[ro][co]+2)continue;   
            b[nr][nc]=b[ro][co]+1;   
            q[0][++r]=nr;   
            q[1][r]=nc;   
        }   
    }   
}   
int main()   
{   
    int i,j,sr,sc,er,ec;   
    scanf("%d%d",&m,&n);   
    for(i=1;i<=n;++i)   
    {   
        for(j=1;j<=m;++j)   
        {   
            scanf("%d",&a[i][j]);   
            if(a[i][j]==4)f[0][++p]=i,f[1][p]=j;   
            if(a[i][j]==2)sr=i,sc=j;   
            if(a[i][j]==3)er=i,ec=j;   
            b[i][j]=1000010;   
        }   
    }   
    b[sr][sc]=0;   
    q[0][1]=sr;   
    q[1][1]=sc;   
    BFS();   
    int t=0;   
    for(i=1;i<=n;++i)   
    {   
        for(j=1;j<=m;++j)   
        {   
            if(a[i][j]==4)f[2][++t]=b[i][j];   
            b[i][j]=1000010;   
        }   
    }   
    b[er][ec]=0;   
    q[0][1]=er;   
    q[1][1]=ec;   
    BFS();   
    t=0;   
    for(i=1;i<=n;++i)   
    {   
        for(j=1;j<=m;++j)   
        {   
            if(a[i][j]==4)f[2][++t]+=b[i][j];   
            if(f[2][t]&&mn>f[2][t])mn=f[2][t];   
        }   
    }   
    printf("%d",mn);   
    return 0;   
}  