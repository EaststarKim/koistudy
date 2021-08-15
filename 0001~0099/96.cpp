#include <stdio.h>
int a[20][20];
int main()
{
    int i,j,n,x,y;
    for(i=1;i<20;++i){
        for(j=1;j<20;++j)scanf("%d",&a[i][j]);
    }
    scanf("%d",&n);
    for(i=0;i<n;++i){
        scanf("%d%d",&x,&y);
        for(j=1;j<20;++j)a[x][j]=!a[x][j],a[j][y]=!a[j][y];
    }
    for(i=1;i<20;++i){
        for(j=1;j<20;++j)printf("%d ",a[i][j]);
        printf("\n");
    }
}
