#include <stdio.h>
int a[20][20],D[20][20];
int main(){
    int i,j,t,n,m,x,ans;
    scanf("%d",&t);
    for(;t--;){
        scanf("%d%d%d",&x,&m,&n);
        for(i=1;i<=n;++i){
            for(j=1;j<=m;++j)scanf("%d",a[i]+j),D[i][j]=0;
        }
        D[1][1]=(a[1][1]!=1);
        for(i=1;i<=n;++i){
            for(j=1;j<=m;++j){
                if(i>x&&a[i-x][j]!=1)D[i][j]+=D[i-x][j];
                if(j>x&&a[i][j-x]!=1)D[i][j]+=D[i][j-x];
                if(a[i][j]>1)ans=D[i][j];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
