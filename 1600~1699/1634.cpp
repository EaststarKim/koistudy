#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int a[2010],b[2010];
long long D[2010][2010],ans=1e18;
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i),b[i]=a[i];
    sort(b+1,b+n+1);
    for(i=1;i<=n;++i)D[1][i]=max(0,a[1]-b[i]);
    for(i=2;i<=n;++i){
        D[i][1]=D[i-1][1]+abs(a[i]-b[1]);
        for(j=2;j<=n;++j)D[i][j]=min(D[i][j-1],D[i-1][j]+abs(a[i]-b[j]));
    }
    for(i=1;i<=n;++i)ans=min(ans,D[n][i]);
    for(i=1;i<=n;++i)a[i]=-a[i],b[i]=-b[i];
    sort(b+1,b+n+1);
    for(i=1;i<=n;++i)D[1][i]=max(0,a[1]-b[i]);
    for(i=2;i<=n;++i){
        D[i][1]=D[i-1][1]+abs(a[i]-b[1]);
        for(j=2;j<=n;++j)D[i][j]=min(D[i][j-1],D[i-1][j]+abs(a[i]-b[j]));
    }
    for(i=1;i<=n;++i)ans=min(ans,D[n][i]);
    printf("%d",ans);
    return 0;
}
