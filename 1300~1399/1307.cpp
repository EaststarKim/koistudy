#include <stdio.h>
int a[11][1010],D[11][1010],p[11][1010],ans=1e9,ai;
int x[]={-1,0,1};
void path(int k,int n){
    if(n==1){
        printf("%d ",k+1);
        return;
    }
    path(p[k][n],n-1);
    printf("%d ",k+1);
}
int main(){
    int i,j,k,c,n,m;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;++i){
        for(j=1;j<=m;++j)scanf("%d",a[i]+j);
    }
    for(i=0;i<n;++i){
        for(j=2;j<=m+1;++j)D[i][j]=1e9;
    }
    for(i=1;i<=m;++i){
        for(j=0;j<n;++j){
            for(k=0;k<3;++k){
                c=(j+x[k]+n)%n;
                if(D[c][i+1]>D[j][i]+a[j][i])D[c][i+1]=D[j][i]+a[j][i],p[c][i+1]=j;
            }
        }
    }
    for(i=0;i<n;++i)if(ans>D[i][m+1])ans=D[i][m+1],ai=i;
    path(p[ai][m+1],m);
    printf("\n%d",ans);
    return 0;
}
