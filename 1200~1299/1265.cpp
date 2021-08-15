#include <stdio.h>
#include <algorithm>
using namespace std;
int a[210][210],t,mn;
int main(){
    int i,j,k,n,m,s,e,d;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)for(j=1;j<=n;++j)a[i][j]=1e9;
    for(i=1;i<=m;++i)scanf("%d%d%d",&s,&e,&d),a[s][e]=a[e][s]=d;
    for(k=1;k<=n;++k){
        for(i=1;i<=n;++i)if(a[i][k]<1e9){
            for(j=1;j<=n;++j)if(a[k][j]<1e9)a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        }
    }
    for(i=2;i<=n;++i)t+=a[1][i];
    mn=t;
    for(i=2;i<=n;++i){
        s=0;
        for(j=1;j<=n;++j)if(i!=j)s+=a[i][j];
        mn=min(mn,s);
    }
    if(mn==t)mn=-1;
    printf("%d",mn);
    return 0;
}
