#include <stdio.h>
int ans[5005][5005],cnt;
int main()
{
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        int a,b,x;
        scanf("%d %d %d",&a,&b,&x);
        if(ans[a][b]<x+1)ans[a][b] = x+1;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            if(ans[i][j]!=0) cnt++;
            if(ans[i+1][j] < ans[i][j]-1) ans[i+1][j] = ans[i][j]-1;
            if(ans[i+1][j+1] < ans[i][j]-1) ans[i+1][j+1] = ans[i][j] -1;
        }
    }
    printf("%d",cnt);
    return 0;
}

