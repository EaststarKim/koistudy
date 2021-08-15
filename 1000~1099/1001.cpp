#include <stdio.h>
#include <algorithm>
using namespace std;
const int MN=-1e8;
int s[5010],t[5010],D[5010][5010],ans=MN;
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",s+i);
    for(i=1;i<=n;++i)scanf("%d",t+i);
    for(i=1;i<=n;++i){
        for(j=0;j<=i;++j)D[i][j]=MN;
        for(j=0;j<i;++j){
            if(D[i-1][j]!=MN)D[i][j+1]=max(D[i][j+1],D[i-1][j]+s[i]+t[i]*j);
            if(i>2&&j>0&&D[i-2][j-1]!=MN)D[i][j]=max(D[i][j],D[i-2][j-1]+s[i]+t[i]*(j-1));
        }
    }
    for(i=2;i<=n;++i)ans=max(ans,D[n][i]);
    printf("%d",ans);
    return 0;
}
