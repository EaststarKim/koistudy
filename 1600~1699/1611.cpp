#include <stdio.h>
#include <algorithm>
using namespace std;
int a[4010][110],D[4010][110];
int main(){
    int i,j,k,n,m,s;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)scanf("%d",a[i]+j);
    }
    for(i=2;i<=n+1;++i){
        for(j=1;j<=m;++j)D[i][j]=-1e9;
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            D[i][j]+=a[i][j];
            s=0;
            for(k=j;--k;)s+=a[i][k],D[i+1][k]=max(D[i+1][k],D[i][j]+s);
            D[i+1][j]=max(D[i+1][j],D[i][j]);
            s=0;
            for(k=j;++k<=m;)s+=a[i][k],D[i+1][k]=max(D[i+1][k],D[i][j]+s);
        }
    }
    int ans=-1e9;
    for(i=1;i<=m;++i)ans=max(ans,D[n+1][i]);
    printf("%d",ans);
    return 0;
}
