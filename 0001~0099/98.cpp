#include <stdio.h>
int a[11][11];
int main()
{
    int i,j,r=2,c=2;
    for(i=1;i<11;++i){
        for(j=1;j<11;++j)scanf("%d",a[i]+j);
    }
    for(;;){
        if(a[r][c]==2){
            a[r][c]=9;
            break;
        }
        a[r][c]=9;
        if(a[r][c+1]!=1)++c;
        else if(a[r+1][c]!=1)++r;
        else break;
    }
    for(i=1;i<11;++i){
        for(j=1;j<11;++j)printf("%d ",a[i][j]);
    }
    return 0;
}
