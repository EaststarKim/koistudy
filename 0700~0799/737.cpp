#include <stdio.h>
#include <algorithm>
using namespace std;
char a[2010],b[2010];
int D[2010][2010][2],ans;
int main(){
    int i,j,k,n,m;
    scanf("%d%d\n%s\n%s",&n,&m,a,b);
    for(i=0;i<n;++i)a[i]=(a[i]=='I');
    for(i=0;i<m;++i)b[i]=(b[i]=='I');
    for(i=0;i<=n;++i){
        for(j=0;j<=m;++j)D[i][j][0]=1;
    }
    for(i=0;i<=n;++i){
        for(j=0;j<=m;++j){
            for(k=0;k<2;++k)if(D[i][j][k]){
                if(i<n&&a[i]!=k)D[i+1][j][!k]=max(D[i+1][j][!k],D[i][j][k]+1);
                if(j<m&&b[j]!=k)D[i][j+1][!k]=max(D[i][j+1][!k],D[i][j][k]+1);
            }
        }
    }
    for(i=0;i<=n;++i){
        for(j=0;j<=m;++j)ans=max(ans,D[i][j][1]);
    }
    printf("%d",ans-1);
    return 0;
}
