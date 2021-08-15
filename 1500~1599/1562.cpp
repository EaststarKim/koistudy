#include <stdio.h>
char a[110][110];
int chk[110][110];
int x[]={-1,-1,0,1,1,1,0,-1},y[]={0,1,1,1,0,-1,-1,-1};
int main(){
    int i,j,k,n,m,r,c;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)scanf("%s",a[i]+1);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            for(k=0;k<8;++k){
                r=i+x[k],c=j+y[k];
                if(r<1||r>n||c<1||c>m||a[r][c]=='#')continue;
                break;
            }
            if(k>7){
                chk[i][j]=1;
                for(k=0;k<8;++k){
                    r=i+x[k],c=j+y[k];
                    if(r<1||r>n||c<1||c>m)continue;
                    chk[r][c]=1;
                }
            }
        }
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)if(a[i][j]=='#'&&!chk[i][j]){
            puts("Bad");
            return 0;
        }
    }
    puts("Good");
    return 0;
}
