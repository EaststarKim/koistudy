#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1010],s[100010],D[1010][1010],ans;
int main(){
    int i,j,n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=k;++i)scanf("%d",a+i),s[a[i]]=1;
    for(i=1;i<=1e5;++i)s[i]+=s[i-1];
    for(i=1;i<=n;++i){
        for(j=1;j<=k;++j)D[i][s[a[j]+m]]=max(D[i][s[a[j]+m]],D[i-1][j-1]+s[a[j]+m]-j+1);
        for(j=1;j<=k;++j)D[i][j]=max(D[i][j],D[i][j-1]);
    }
    for(i=1;i<=k;++i)ans=max(ans,D[n][i]);
    printf("%d",k-ans);
    return 0;
}
