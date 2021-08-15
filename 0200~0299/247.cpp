#include <stdio.h>
int d[21][2000][2000],s,mn=2000,mj,mk;
int main()
{
    int i,j,k,n,m;
    scanf("%d",&n);
    d[0][0][0]=1;
    for(i=1;i<=n;++i)
    {
        scanf("%d",&m);
        for(j=0;j<=s;++j)
        {
            for(k=0;k<=s;++k)
            {
                if(d[i-1][j][k])d[i][j+m][k]=d[i][j][k+m]=d[i][j][k]=1;
            }
        }
        s+=m;
    }
    for(j=(s+2)/3;j<=s;++j)
    {
        for(k=(s-j+1)/2;k<=j;++k)
        {
            if(d[n][j][k]&&mn>j-s+j+k)mn=j-s+j+k,mj=j,mk=k;
        }
    }
    printf("%d %d %d",mj,mk,s-mj-mk);
    return 0;
}
