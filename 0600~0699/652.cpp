#include <stdio.h>   
#define MAX 40010   
int a[110][110],b[5][110][110],q[3][40010],f,r=1;   
int main()   
{   
    int i,j,l,n,m,sr,sc,sd,er,ec,ed,ro,co,d,nr,nc;   
    char ssd,eed;   
    scanf("%d%d",&n,&m);   
    for(i=1;i<=n;++i)   
    {   
        for(j=1;j<=m;++j)   
        {   
            scanf("%d",a[i]+j);   
            for(l=1;l<5;++l)b[l][i][j]=MAX;   
        }   
    }   
    scanf("%d%d %c %d%d %c ",&sr,&sc,&ssd,&er,&ec,&eed);   
    if(ssd=='E')sd=1;   
    if(ssd=='W')sd=2;   
    if(ssd=='S')sd=3;   
    if(ssd=='N')sd=4;   
    if(eed=='E')ed=1;   
    if(eed=='W')ed=2;   
    if(eed=='S')ed=3;   
    if(eed=='N')ed=4;   
    b[sd][sr][sc]=0;   
    q[0][1]=sr;   
    q[1][1]=sc;   
    q[2][1]=sd;   
    while(f<r)   
    {   
        ro=q[0][++f];   
        co=q[1][f];   
        d=q[2][f];   
        for(l=1;;++l)   
        {   
            if(d<2)nr=ro,nc=co+l;   
            if(d==2)nr=ro,nc=co-l;   
            if(d==3)nr=ro+l,nc=co;   
            if(d>3)nr=ro-l,nc=co;   
            if(nr<1||nr>n||nc<1||nc>m)break;   
                        if(a[nr][nc])break;   
            if(b[d][nr][nc]<b[d][ro][co]+2)continue;   
            b[d][nr][nc]=b[d][ro][co]+1;   
            q[0][++r]=nr;   
            q[1][r]=nc;   
            q[2][r]=d;   
        }   
        if(d<3)   
        {   
            if(b[3][ro][co]>b[d][ro][co]+1)q[0][++r]=ro,q[1][r]=co,q[2][r]=3,b[3][ro][co]=b[d][ro][co]+1;   
            if(b[4][ro][co]>b[d][ro][co]+1)q[0][++r]=ro,q[1][r]=co,q[2][r]=4,b[4][ro][co]=b[d][ro][co]+1;   
        }   
        if(d>2)   
        {   
            if(b[1][ro][co]>b[d][ro][co]+1)q[0][++r]=ro,q[1][r]=co,q[2][r]=1,b[1][ro][co]=b[d][ro][co]+1;   
            if(b[2][ro][co]>b[d][ro][co]+1)q[0][++r]=ro,q[1][r]=co,q[2][r]=2,b[2][ro][co]=b[d][ro][co]+1;   
        }   
    }   
    printf("%d",b[ed][er][ec]);   
    return 0;   
}  