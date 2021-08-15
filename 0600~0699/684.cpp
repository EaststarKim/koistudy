#include <stdio.h>
#include <algorithm>
using namespace std;
char c[110][31];
int D[110][31],ans=101;
int main()
{
    int i,j,k,n,m,s,e;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)scanf("%s",c[i]+1);
    scanf("%d%d",&s,&e);
    for(i=s-1;i<e;++i){
        for(j=0;j<=m;++j)D[i][j]=101;
    }
    D[s-1][0]=0;
    for(i=s;i<e;++i){
        for(j=0;j<=m;++j){
            for(k=1;k<=m;++k)if(c[i][k]=='O')D[i][k]=min(D[i][k],D[i-1][j]+(j!=k));
        }
    }
    for(i=1;i<=m;++i)ans=min(ans,D[e-1][i]);
    if(ans==101)ans=0;
    printf("%d",ans-1);
    return 0;
}
