#include <stdio.h>   
#include <algorithm>   
#define min(a,b) a<b? a:b   
int D[25][25][25];   
int main()   
{   
    int i,j,k,n,m,x,y,t,min=999;   
    scanf("%d%d%d%d",&n,&x,&y,&m);   
    for(i=1;i<=m;++i)   
    {   
        for(j=1;j<=n;++j)   
        {   
            for(k=1;k<=n;++k)D[i][j][k]=999;   
        }   
    }   
    D[0][x][y]=0;   
    scanf("%d",&t);   
    if(t!=x&&t!=y)D[1][t][y]=abs(t-x),D[1][x][t]=abs(t-y);   
    for(i=2;i<=m;++i)   
    {   
        scanf("%d",&x);   
        for(j=1;j<=n;++j)   
        {   
                D[i][x][j]=min(D[i][x][j],D[i-1][t][j]+abs(x-t));   
                D[i][t][x]=min(D[i][t][x],D[i-1][t][j]+abs(x-j));   
                D[i][x][t]=min(D[i][x][t],D[i-1][j][t]+abs(x-j));   
                D[i][j][x]=min(D[i][j][x],D[i-1][j][t]+abs(x-t));   
        }   
        t=x;   
    }   
    for(i=1;i<=n;++i)   
    {   
            if(min>D[m][t][i])min=D[m][t][i];   
            if(min>D[m][i][t])min=D[m][i][t];   
    }   
    printf("%d",min);   
    return 0;   
} 