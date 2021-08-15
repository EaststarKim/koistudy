#include <stdio.h>            
int b[205][105];         
           
int main()            
{            
    int i,j,k,n,m;            
    scanf("%d %d",&n,&m);            
    for(j=0;j<=m;j++)            
    {            
        b[0][j] = 1;            
        b[1][j] = 1;            
    }            
    b[1][0] = 0;            
    for(i=2;i<=n;i++)            
    {            
        for(j=0;j<=m;j++)            
        {            
            for(k=2;k<i;k++)            
            {            
                b[i][j] += b[i-k][j-1]*b[k-1][j-1]%9901;            
            }            
            b[i][j]%=9901;            
        }            
    }            
    if(b[n][m]<b[n][m-1])printf("%d\n",9901+(b[n][m]-b[n][m-1]));          
    else printf("%d\n",b[n][m]-b[n][m-1]);            
} 