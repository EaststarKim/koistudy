#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1010],s[1002010],k,mx;
int main(){
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=0;i<=n;++i)for(j=i;j<=n;++j)if(a[i]+a[j]<=m)s[++k]=a[i]+a[j];
    sort(s+1,s+k+1);
    for(i=1;i<=k;++i)mx=max(mx,s[i]+s[upper_bound(s+1,s+k+1,m-s[i])-s-1]);
    printf("%d",mx);
    return 0;
}
