#include <stdio.h>
char a[110][110];
int x[]={-1,-1,0,1,1,1,0,-1},y[]={0,1,1,1,0,-1,-1,-1};
int main(){
    int i,j,k,r,c,n,m,t;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)scanf("%s",a[i]+1);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            if(a[i][j]=='.'){
                for(t=k=0;k<8;++k){
                    r=i+x[k],c=j+y[k];
                    if(0<r&&r<=n&&0<c&&c<=m&&a[r][c]=='*')++t;
                }
                printf("%d",t);
            }
            else printf("*");
        }
        puts("");
    }
    return 0;
}
