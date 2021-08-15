#include <stdio.h>
int a[30][30];
int main()
{
    int i,j,R,C,k,r,c;
    scanf("%d%d%d",&R,&C,&k);
    for(i=1;i<=k;++i){
        scanf("%d%d",&r,&c);
        a[r][c]=-1;
    }
    a[1][1]=1;
    for(i=1;i<=R;++i){
        for(j=1;j<=C;++j){
            if(a[i][j])continue;
            if(a[i-1][j]>=0)a[i][j]+=a[i-1][j];
            if(a[i][j-1]>=0)a[i][j]+=a[i][j-1];
            a[i][j]%=1000000000;
        }
    }
    printf("%d",a[R][C]);
    return 0;
}
