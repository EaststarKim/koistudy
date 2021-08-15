#include <stdio.h>
int a[110][110];
int main()
{
    int i,j,h,w,n,l,d,x,y;
    scanf("%d%d%d",&h,&w,&n);
    for(i=1;i<=n;++i){
        scanf("%d%d%d%d",&l,&d,&x,&y);
        for(j=0;j<l;++j){
            if(d)a[x+j][y]=1;
            else a[x][y+j]=1;
        }
    }
    for(i=1;i<=h;++i){
        for(j=1;j<=w;++j)printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
