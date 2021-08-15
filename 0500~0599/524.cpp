#include <stdio.h>
#include <algorithm>
using namespace std;
int a[5010],c[100010],D[5010];
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    sort(a+1,a+n+1);
    for(i=1;~scanf("%d",c+i);++i);
    for(--i;--i;)if(c[i]>c[i+1])c[i]=c[i+1];
    for(i=1;i<=n;++i){
        D[i]=1e7;
        for(j=0;j<i;++j)D[i]=min(D[i],D[j]+c[a[i]-a[j+1]+1]);
    }
    printf("%d",D[n]);
    return 0;
}
