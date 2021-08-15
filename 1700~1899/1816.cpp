#include <bits/stdc++.h>
using namespace std;
int chk[110],D[110][110];
int main(){
    int i,j,k,n,m,t,ans=1e9;
    scanf("%d%d",&n,&m);
    for(;m--;)scanf("%d",&t),chk[t]=1;
    for(i=1;i<=n;++i){
        for(j=0;j<=n;++j)D[i][j]=1e9;
    }
    D[0][0]=0;
    for(i=0;i<n;++i){
        for(j=0;j<=i;++j)if(D[i][j]<1e9){
            D[i+1][j]=min(D[i+1][j],D[i][j]+10000);
            if(j>2)D[i+1][j-3]=min(D[i+1][j-3],D[i][j]);
            for(k=1;k<=3;++k)D[i+k][j+1]=min(D[i+k][j+1],D[i][j]+25000);
            for(k=1;k<=5;++k)D[i+k][j+2]=min(D[i+k][j+2],D[i][j]+37000);
        }
        if(chk[i+1])for(j=0;j<=i;++j)D[i+1][j]=min(D[i+1][j],D[i][j]);
    }
    for(i=0;i<=n;++i)ans=min(ans,D[n][i]);
    printf("%d",ans);
    return 0;
}
