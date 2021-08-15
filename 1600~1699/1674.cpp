#include <stdio.h>
#include <algorithm>
using namespace std;
int a[510][510],d[510],e[510],tmp[510];
int main(){
    int i,j,k,n,m,w,x,y,z;
    scanf("%d%d%d",&n,&m,&w);
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)a[i][j]=1e9;
    }
    for(i=1;i<=m;++i){
        scanf("%d%d%d",&x,&y,&z);
        a[x][y]=min(a[x][y],z);
        a[y][x]=min(a[y][x],z);
    }
    for(i=1;i<=w;++i){
        scanf("%d%d%d",&x,&y,&z);
        a[x][y]=min(a[x][y],-z);
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)e[j]=d[j];
        for(j=1;j<=n;++j){
            for(k=1;k<=n;++k){
                if(d[k]>e[j]+a[j][k])d[k]=e[j]+a[j][k];
            }
        }
    }
    int flag=0;
    for(j=1;j<=n;++j)e[j]=d[j];
    for(j=1;j<=n;++j){
        for(k=1;k<=n;++k){
            if(d[k]>e[j]+a[j][k])d[k]=e[j]+a[j][k],flag=1;
        }
    }
    puts(flag?"YES":"NO");
    return 0;
}
