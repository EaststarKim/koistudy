#include <stdio.h>
int a[9][1010],p[2][500000];
int main()
{
    int i,j,n,k,s,e;
    scanf("%d%d",&n,&k);
    for(i=1;i<=k;++i)scanf("%d%d",&p[0][i],&p[1][i]);
    scanf("%d%d",&s,&e);
    a[0][s]=1;
    for(i=1;i<9;++i)
    {
        for(j=1;j<=k;++j)
        {
            if(a[i-1][p[0][j]])a[i][p[1][j]]+=a[i-1][p[0][j]],a[i][p[1][j]]%=88888;
            if(a[i-1][p[1][j]])a[i][p[0][j]]+=a[i-1][p[1][j]],a[i][p[0][j]]%=88888;
        }
    }
    printf("%d",a[8][e]);
    return 0;
}
