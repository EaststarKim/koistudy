#include <cstdio>
int a[310][21],b[310][21],d[310];
int main()
{
    int i,j,k,l,n,m,p;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&p);
        for(j=1;j<=m;++j)scanf("%d",&a[p][j]);
    }
    for(i=1;i<=n;++i)
    {
        for(j=0;j<i;++j)
        {
            for(k=1;k<=m;++k)
            {
                if(d[i]<d[j]+a[b[j][k]+i-j][k]-a[b[j][k]][k])
                {
                    d[i]=d[j]+a[b[j][k]+i-j][k]-a[b[j][k]][k];
                    for(l=1;l<=m;++l)b[i][l]=b[j][l];
                    b[i][k]+=i-j;
                }
            }
        }
    }
    printf("%d\n",d[n]);
    for(i=1;i<=m;++i)printf("%d ",b[n][i]);
    return 0;
}
