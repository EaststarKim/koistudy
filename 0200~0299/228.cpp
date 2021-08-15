#include <stdio.h>
int a[25][25],d[5];
int xx[4]={-1,0,1,1},yy[4]={1,1,1,0};
int back(int i,int j)
{
    int k,l,cnt;
    if(a[i][j]==0) return 0;
    for(k=0;k<4;++k)
    {
        if(a[i-xx[k]][j-yy[k]]!=a[i][j])
        {
            cnt=1;
            for(l=1;l<6&&i+xx[k]*l<20&&j+yy[k]*l<20&&i+xx[k]*l>0;++l)
            {
                if(a[i][j]!=a[i+xx[k]*l][j+yy[k]*l])break;
                ++cnt;
            }
            if(cnt==5)
            {
                printf("%d\n%d %d",a[i][j],i,j);
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int i,j;
    for(i=1;i<20;++i)
    {
        for(j=1;j<20;++j)scanf("%d",&a[i][j]);
    }
    for(i=1;i<20;++i)
    {
        for(j=1;j<20;++j)
        {
            if(back(i,j))return 0;
        }
    }
    printf("0");
    return 0;
}
