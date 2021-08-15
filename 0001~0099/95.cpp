#include <stdio.h>
int a[20][20];
int main()
{
    int i,j,n,x,y;
    scanf("%d",&n);
    for(i=0;i<n;++i)scanf("%d%d",&x,&y),a[x][y]=1;
    for(i=1;i<20;++i)
    {
        for(j=1;j<20;++j)printf("%d ",a[i][j]);
        printf("\n");
    }
}
