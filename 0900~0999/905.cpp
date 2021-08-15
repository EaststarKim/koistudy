#include <stdio.h>
#include <algorithm>
using namespace std;
int a[5010],c[100010],D[5010];
int main(){
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)scanf("%d",a+i),D[i]=1e9;
    sort(a+1,a+n+1);
    for(i=1;i<=m;++i)scanf("%d",c+i);
    for(i=m;--i;)c[i]=min(c[i],c[i+1]);
    for(i=1;i<=n;++i){
        for(j=0;j<i;++j)D[i]=min(D[i],D[j]+c[a[i]-a[j+1]+1]);
    }
    printf("%d",D[n]);
    return 0;
}
