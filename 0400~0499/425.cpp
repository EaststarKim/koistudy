#include <stdio.h>
#include <algorithm>
#include <functional>
using namespace std;
int a[11][2010],b[11],D[11][2010];
int main(){
    int i,j,k,n,m,c,g;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        scanf("%d%d",&c,&g);
        a[g][++b[g]]=c;
    }
    for(i=1;i<11;++i){
        sort(a[i]+1,a[i]+b[i]+1,greater<int>());
        for(j=1;j<b[i];++j)a[i][j+1]+=a[i][j]+j*2;
    }
    for(i=1;i<11;++i){
        for(j=0;j<=b[i];++j){
            for(k=j;k<=m;++k)D[i][k]=max(D[i][k],D[i-1][k-j]+a[i][j]);
        }
    }
    printf("%d",D[10][m]);
    return 0;
}
