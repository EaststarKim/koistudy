#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int s,a,b;
    bool operator<(const data&r)const{
        return a*r.b>r.a*b;
    }
}a[1010];
int D[1010][3010]={{1}},ans;
int main(){
    int i,j,n,t;
    scanf("%d%d",&n,&t);
    for(i=1;i<=n;++i)scanf("%d%d%d",&a[i].s,&a[i].a,&a[i].b);
    sort(a+1,a+n+1);
    for(i=1;i<=n;++i){
        for(j=0;j<=t;++j)D[i][j]=D[i-1][j];
        for(j=0;j<=t;++j)if(D[i-1][j])D[i][j+a[i].b]=max(D[i][j+a[i].b],D[i-1][j]+a[i].s-a[i].a*(j+a[i].b));
    }
    for(i=0;i<=t;++i)ans=max(ans,D[n][i]);
    printf("%d",ans-1);
    return 0;
}
