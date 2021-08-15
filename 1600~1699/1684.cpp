#include <stdio.h>
#include <algorithm>
using namespace std;
int a[110][110];
int main(){
    int i,j,k,n,m,x,y,s,e;
    scanf("%d%d%d%d",&n,&x,&y,&m);
    for(i=1;i<=m;++i){
        scanf("%d%d",&s,&e);
        a[s][e]=a[e][s]=1;
    }
    for(k=1;k<=n;++k){
        for(i=1;i<=n;++i)if(a[i][k]){
            for(j=1;j<=n;++j)if(a[k][j]){
                if(a[i][j])a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
                else a[i][j]=a[i][k]+a[k][j];
            }
        }
    }
    if(!a[x][y])a[x][y]=-1;
    printf("%d",a[x][y]);
    return 0;
}
