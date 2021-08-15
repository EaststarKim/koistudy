#include <stdio.h>
int n,a[1030][1030];
void back(int sr,int er,int sc,int ec)
{
    int i,j,z=0,o=0,m,k;
    if(sr==er)
    {
        printf("%d",a[sr][sc]);
        return;
    }
    for(i=sr;i<=er;++i)
    {
        for(j=sc;j<=ec;++j)
        {
            if(a[i][j]==0)z=1;
            else o=1;
            if(z&&o)break;
        }
        if(z&&o)break;
    }
    if(z&&o)
    {
        printf("X");
        m=(sr+er)/2;
        k=(sc+ec)/2;
        back(sr,m,sc,k);
        back(sr,m,k+1,ec);
        back(m+1,er,sc,k);
        back(m+1,er,k+1,ec);
        return;
    }
    if(z)
    {
        printf("0");
        return;
    }
    printf("1");
    return;
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)scanf("%d",&a[i][j]);
    }
    back(1,n,1,n);
    return 0;
}
